#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#include "client_handler.h"

#define QUEUE_SIZE 10

int main() {
  Socket sv("8080", QUEUE_SIZE);
  Socket client;
  Socket client2;
  Resources resultados;
  sv.accept_client(client);
  ClientHandler(client, resultados);
  sv.accept_client(client2);
  ClientHandler(client2, resultados);
  return 0;
}
