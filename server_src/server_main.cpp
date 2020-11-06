#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#include "accepter.h"

#define QUEUE_SIZE 10
#define EXIT_CHAR "q"

int main() {
  Socket sv("8080", QUEUE_SIZE);
  Accepter aceptador(sv);
  aceptador.start();
  std::string buffer;
  while (buffer != EXIT_CHAR) std::getline(std::cin, buffer);
  aceptador.stop();
  aceptador.join();
  return 0;
}
