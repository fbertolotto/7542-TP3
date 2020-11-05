#include "client_handler.h"

#include <iostream>

ClientHandler::ClientHandler(Socket& client, Resources& res)
    : sk(client), resources(res) {
  run();
}

void ClientHandler::run() {
  std::string msg;
  sk.recv_msg(msg);
  pp.process(msg);
  if (validate()) {
    std::cout << "ES VALIDO\n";
    execute_method();
  } else {
    std::cout << "ES INVALIDO\n";
    sk.send_msg("ERROR\n", 6);
  }
  resources.show_all();
}

bool ClientHandler::validate() {
  std::string method = pp.get_method();
  if (method != "GET" && method != "POST") return false;

  std::string resource = pp.get_resource();
  if (method == "POST" && resource == "/") return false;

  if (method == "GET") {
    std::string body = resources.get_resource(resource);
    if (body.size() == 0) return false;
  }
  return true;
}

void ClientHandler::execute_method() {
  std::string method = pp.get_method();
  if (method == "POST") {
    resources.add_resource(pp.get_resource(), pp.get_body());
    sk.send_msg("TODO OK\n", 8);
  } else {
    std::string resource = resources.get_resource(pp.get_resource());
    send_to_client(resource);
  }
}

void ClientHandler::send_to_client(std::string msg) {
  std::string success = "HTTP 200 OK\n\n";
  success.append(msg);
  sk.send_msg(success, success.size());
}
