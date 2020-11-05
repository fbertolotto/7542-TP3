#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#include "accepter.h"

#define QUEUE_SIZE 10

int main() {
  Socket sv("8080", QUEUE_SIZE);
  Accepter aceptador(sv);
  aceptador.run();
  return 0;
}
