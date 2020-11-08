
#include <sstream>
#include <string>

#include "client.h"

int main(int argc, char** argv) {
  if (argc != 3) return 0;
  try {
    Client client(argv[1], argv[2]);
    std::stringstream text;
    std::string stdin_buf;
    while (getline(std::cin, stdin_buf)) text << stdin_buf << "\n";
    client.send_msg(text.str());
    client.show_response();
  } catch (const ConnectionError& error) {
    std::cout << error.what();
  }
  return 0;
}
