#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#include "client_handler.h"

#define QUEUE_SIZE 10

int main() {
  Socket sv("8080", QUEUE_SIZE);
  Socket client;
  Resources resultados;

  sv.accept_client(client);
  std::cout << "Resultado final:\n";
  ClientHandler(client, resultados);

  /*
    Socket client("localhost", "8080");
    client.connect_to_sv();
    client.send_msg(msg, msg.size());
  */
  return 0;
}