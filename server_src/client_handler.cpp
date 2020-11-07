#include "client_handler.h"

#include <unistd.h>

#include <iostream>

ClientHandler::ClientHandler(Socket& client, Resources& res)
    : resources(res), finished(false) {
  sk = std::move(client);
}

bool ClientHandler::finish() { return finished; }

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
  sk.send_msg(response, response.size());
  sk.stop_sending();
}

void ClientHandler::show_command() {
  std::cout << pp.get_method() << " " << pp.get_resource() << " "
            << pp.get_protocol() << "\n";
}

ClientHandler::~ClientHandler() { sk.stop(); }
