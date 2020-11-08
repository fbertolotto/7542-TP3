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
  } catch (const FileError& error) {
    std::cout << error.what();
  } catch (const ConnectionError& error) {
    std::cout << error.what();
  } catch (...) {
    std::cout << "Error desconocido\n";
  }
  return 0;
}
