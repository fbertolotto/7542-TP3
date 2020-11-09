#ifndef SOCKET_H
#define SOCKET_H

#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <string>

#include "connection_error.h"

class Socket {
 private:
  int file_d;
  struct addrinfo* info;

  /* Setea los flags necesarios para IPV4 - HTTP */
  void _set_net_flags(struct addrinfo* hints);
  /* Itera los resultados del sistema operativo en busca
  de lograr una conexión del socket */
  void _start();
  /* Bindea un socket al puerto correspondiente */
  void _bind();
  /* Pone el socket en modo de escucha, recibe la cantidad
  maxima de clientes posibles en espera simultáneos */
  void _listen(int queue_size);
  /* Conecta el socket al host correspondiente*/
  void _connect_to_sv();

 public:
  /* Init del socket para un cliente, recibe el host/servidor y el puerto */
  Socket(const char* host, const char* port);

  /* Init del socket para un servidor, recibe el puerto y la cantidad maxima
  de clientes en espera de ser aceptados simultaneamente */
  Socket(const char* port, int queue);

  /* Init de un socket invalido/vacio */
  Socket();

  /* Finaliza el canal de escritura del socket. No se podran enviar mas datos */
  void stop_sending();

  /* Acepta un cliente de la cola de espera del servidor. Recibe el socket en
  donde se realizara la comunicacion con el aceptado */
  void accept_client(Socket& client);

  /* Envia un mensaje a traves del socket. Recibe el mensaje y el largo*/
  void send_msg(std::string msg, int len);

  /* Recibe el mensaje y lo devuelve como string */
  std::string recv_msg();

  /* Finaliza el socket, apaga ambos canales y cierra el socket */
  void stop();

  /* Se permite el constructor por movimiento */
  Socket(Socket&& other);

  /* No se permiten copias*/
  Socket& operator=(const Socket&) = delete;
  Socket& operator=(Socket&&) = delete;
  Socket(const Socket&) = delete;

  /* Destructor del socket */
  ~Socket();
};

#endif  // SOCKET_H
