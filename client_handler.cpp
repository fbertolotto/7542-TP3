#include "client_handler.h"

#include <iostream>

ClientHandler::ClientHandler(Socket& client, Resources& res)
    : sk(client), resources(res) {
  run();
}

void ClientHandler::run() {
  std::string msg;
  sk.recv_msg(msg);
  // std::cout << msg << "\n";
  pp.process(msg);
  pp.show_all();
}