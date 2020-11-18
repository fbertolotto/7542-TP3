#include "client.h"

#include <iostream>

Client::Client(char* host, char* port) : sk(host, port), protocol(sk) {
  working = true;
}

void Client::send_msg(std::string& msg) {
  sk.send_msg(msg.c_str(), msg.size());
  sk.stop_sending();
}

void Client::show_response() { std::cout << protocol.get_full_msg(); }

Client::~Client() {
  if (working) sk.stop();
}
