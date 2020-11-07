#include <iostream>
#include <sstream>
#include <string>

#include "../common_src/socket.h"
int main(int argc, char** argv) {
  Socket client("localhost", "8080");
  client.connect_to_sv();
  std::stringstream text;
  std::string stdin_buf;
  while (getline(std::cin, stdin_buf)) {
    text << stdin_buf << "\n";
  }

  std::string order = text.str();
  client.send_msg(order, order.size());

  client.stop_sending();
  std::string buffer;
  client.recv_msg(buffer);
  std::cout << buffer;
  return 0;
}
