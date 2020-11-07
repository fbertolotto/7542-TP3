#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#include "web_server.h"

#define QUEUE_SIZE 10
#define EXIT_CHAR "q"

int main(int argc, char** argv) {
  if (argc < 3) return 0;
  WebServer server(argv[1], argv[2]);
  server.start();
  std::string buffer;
  while (buffer != EXIT_CHAR) std::getline(std::cin, buffer);
  server.stop();
  return 0;
}
