#include "protocol.h"

#include <sstream>
#include <string>

#define RECV_BUFFER_LEN 64

Protocol::Protocol(Socket& socket) : sk(socket) {}

std::string Protocol::get_full_msg() {
  std::stringstream text;
  char buffer[RECV_BUFFER_LEN];
  int bytes;
  while ((bytes = sk.recv_msg(buffer, RECV_BUFFER_LEN)) != 0) {
    for (int i = 0; i < bytes; i++) {
      text << buffer[i];
    }
  }
  return text.str();
}

Protocol::~Protocol() {}
