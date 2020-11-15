#include "client.h"

#include <iostream>
#include <sstream>

#define RECV_BUFFER_LEN 64

Client::Client(char* host, char* port) : sk(host, port) { working = true; }

void Client::send_msg(std::string& msg) {
  sk.send_msg(msg.c_str(), msg.size());
  sk.stop_sending();
}

void Client::show_response() {
  std::stringstream text;
  char buffer[RECV_BUFFER_LEN];
  int bytes;
  while ((bytes = sk.recv_msg(buffer, RECV_BUFFER_LEN)) != 0) {
    for (int i = 0; i < bytes; i++) {
      text << buffer[i];
    }
  }
  std::cout << text.str();
}

Client::~Client() {
  if (working) sk.stop();
}
