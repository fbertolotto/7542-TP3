#include "client.h"

#include <iostream>

Client::Client(char* host, char* port) : sk(host, port) { working = true; }

void Client::send_msg(std::string msg) {
  sk.send_msg(msg, msg.size());
  sk.stop_sending();
}

void Client::show_response() {
  std::string buffer;
  sk.recv_msg(buffer);
  std::cout << buffer;
}

Client::~Client() {
  if (working) sk.stop();
}