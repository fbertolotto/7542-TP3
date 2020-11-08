#ifndef SOCKET
#define SOCKET

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
  void _set_net_flags(struct addrinfo* hints);
  void _start();
  void _bind();
  void _listen(int queue_size);
  void _connect_to_sv();

 public:
  Socket(const char* host, const char* port);
  Socket(const char* port, int queue);
  Socket();
  void stop_sending();
  void accept_client(Socket& client);
  void send_msg(std::string msg, int len);
  void recv_msg(std::string& buffer);
  void stop();

  Socket(Socket&& other);
  Socket& operator=(Socket&& other);
  ~Socket();
};

#endif
