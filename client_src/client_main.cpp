#include <iostream>
#include <string>

#include "../common_src/socket.h"
int main(int argc, char** argv) {
  Socket client("localhost", "8080");
  client.connect_to_sv();
  std::string c1 = argv[1];
  std::string msg = c1 + " /root HTTP1.1\n\nHOLA!";
  client.send_msg(msg, msg.size());
  std::string buffer;
  client.recv_msg(buffer);
  std::cout << buffer;
  return 0;
}
