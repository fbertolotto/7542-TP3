#ifndef CLIENT
#define CLIENT

#include <string>

#include "../common_src/socket.h"

class Client {
 private:
  Socket sk;
  bool working = false;

 public:
  /* Init del cliente, recibe el host y el puerto a donde
  conectarse */
  Client(char* host, char* port);

  /* Envia un mensaje al servidor y cierra el canal de escritura */
  void send_msg(std::string& msg);

  /* Muestra por salida estandar la respuseta del servidor */
  void show_response();

  /* Se prohíben constructores no default */
  Client(const Client&) = delete;
  Client(Client&&) = delete;

  /* Se prohíben las copia */
  Client& operator=(const Client&) = delete;
  Client& operator=(Client&& other) = delete;

  /* Destructor del cliente */
  ~Client();
};

#endif  // CLIENT
