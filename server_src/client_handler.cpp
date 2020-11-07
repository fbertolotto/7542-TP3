#include "client_handler.h"

#include <iostream>

ClientHandler::ClientHandler(Socket& client, Resources& res)
    : resources(res), finished(false) {
  sk = std::move(client);
}

void ClientHandler::run() {
  std::string msg;
  sk.recv_msg(msg);
  pp.process(msg);
  show_command();
  execute_method();
  finished = true;
}

void ClientHandler::execute_method() {
  std::string method = pp.get_method();
  std::string resource = pp.get_resource();

  /* POST RECURSO */
  std::string response;
  if (method == "POST" && resource != "/") {
    resources.add_resource(resource, pp.get_body());
  } else {
    Message* msg = mh.create_message(method, resource, resources);
    response = msg->get_message();
    delete msg;
  }
  if (!finished) {
    sk.send_msg(response, response.size());
    sk.stop_sending();
  }
}

void ClientHandler::send_to_client(std::string msg) {
  std::string success = "HTTP 200 OK\n\n";
  success.append(msg);
  sk.send_msg(success, success.size());
}

void ClientHandler::show_command() {
  std::cout << pp.get_method() << " " << pp.get_resource() << " "
            << pp.get_protocol() << "\n";
}

void ClientHandler::stop() {
  sk.stop();
  finished = true;
}