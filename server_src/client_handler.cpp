#include "client_handler.h"

#include <iostream>

ClientHandler::ClientHandler(Socket& client, Resources& res) : resources(res) {
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
  if (method == "POST" && resource != "/") {
    resources.add_resource(resource, pp.get_body());
    sk.send_msg("", 0);

    /* GET ROOT */
  } else if (method == "GET" && resource == "/") {
    std::string success = "HTTP 200 OK\nContent-Type: text/html\n\n";
    sk.send_msg(success, success.size());

    /* GET RECURSO */
  } else if (method == "GET" && resource != "/") {
    std::string body = resources.get_resource(resource);
    if (body.size() == 0) {
      std::string error = "HTTP 404 NOT FOUND\n\n";
      sk.send_msg(error, error.size());
    } else {
      send_to_client(body);
    }

    /* POST ROOT */
  } else if (method == "POST" && resource == "/") {
    std::string error = "HTTP 403 FORBIDDEN\n\n";
    sk.send_msg(error, error.size());
  } else {
    std::string error = "HTTP 405 METHOD NOT ALLOWED\n\n";
    sk.send_msg(error, error.size());
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