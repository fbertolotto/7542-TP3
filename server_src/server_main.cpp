#include <iostream>
#include <string>

#include "web_server.h"

#define QUEUE_SIZE 10
#define EXIT_CHAR "q"

int main(int argc, char** argv) {
  if (argc != 3) return 1;
  try {
    WebServer server(argv[1], argv[2]);
    server();
    std::string buffer;
    while (buffer != EXIT_CHAR) std::getline(std::cin, buffer);
    return 0;
  } catch (const std::exception& error) {
    std::cout << error.what();
    return 0;
  }
}
