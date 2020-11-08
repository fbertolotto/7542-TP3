#include "socket.h"

#include <cstdint>
#include <cstring>
#include <sstream>
#include <utility>
#include <vector>

/* Socket vació invalido */
Socket::Socket() : file_d(-1), info(NULL) {}

/* Servidor */
Socket::Socket(const char* port, int queue) {
  struct addrinfo hints;
  _set_net_flags(&hints);
  int get_info = getaddrinfo(NULL, port, &hints, &info);
  if (get_info)
    throw ConnectionError("No se encontro informacion de la direccion\n");
  try {
    _start();
    _bind();
    _listen(queue);
  } catch (const ConnectionError& error) {
    freeaddrinfo(info);
    throw;
  }
}

/* Cliente */
Socket::Socket(const char* host, const char* port) {
  struct addrinfo hints;
  _set_net_flags(&hints);
  int get_info = getaddrinfo(host, port, &hints, &info);
  if (get_info)
    throw ConnectionError("No se encontró información de la dirección\n");
  try {
    _connect_to_sv();
  } catch (const ConnectionError& error) {
    freeaddrinfo(info);
    throw;
  }
}

Socket::Socket(Socket&& other) {
  this->file_d = std::move(other.file_d);
  this->info = NULL;
}

void Socket::_set_net_flags(struct addrinfo* hints) {
  memset(hints, 0, sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM;
  hints->ai_flags = 0;
}

void Socket::_start() {
  struct addrinfo* data;
  int tmp_sk = -1;
  for (data = info; data != NULL; data = data->ai_next) {
    tmp_sk = socket(data->ai_family, data->ai_socktype, data->ai_protocol);
    if (tmp_sk != -1) break;
  }
  if (tmp_sk == -1)
    throw ConnectionError("Falló la inicialización del socket\n");
  int val = 1;
  file_d = tmp_sk;
  setsockopt(file_d, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
}

void Socket::_bind() {
  int res = bind(file_d, info->ai_addr, info->ai_addrlen);
  if (res == -1) throw ConnectionError("Falló el bindeo del puerto\n");
}

void Socket::_listen(int queue_size) {
  int res = listen(file_d, queue_size);
  if (res == -1) throw ConnectionError("Falló el listen\n");
  freeaddrinfo(info);
}

void Socket::accept_client(Socket& client) {
  struct sockaddr adrr;
  socklen_t adrrlen = (socklen_t)sizeof(adrr);
  int res = accept(file_d, &adrr, &adrrlen);
  if (res == -1) throw ConnectionError("No se pudo aceptar al cliente\n");
  client.file_d = res;
}

void Socket::_connect_to_sv() {
  struct addrinfo* sv;
  int connected = -1;
  for (sv = info; sv != NULL; sv = sv->ai_next) {
    _start();
    connected = connect(file_d, sv->ai_addr, sv->ai_addrlen);
    if (connected != -1) break;
  }
  if (connected == -1) throw ConnectionError("No se encontró el servidor\n");
  freeaddrinfo(info);
}

void Socket::send_msg(std::string msg, int len) {
  int total_bytes = 0;
  while (total_bytes < len) {
    int bytes =
        send(file_d, &msg[total_bytes], len - total_bytes, MSG_NOSIGNAL);
    if (bytes == -1) throw ConnectionError("Falló el envío del mensaje\n");
    total_bytes += bytes;
  }
}

std::string Socket::recv_msg() {
  std::string text;
  int bytes = 1;
  while (bytes > 0) {
    std::vector<char> tmp_buf(64);
    bytes = recv(file_d, tmp_buf.data(), tmp_buf.size(), 0);
    if (bytes == -1) throw ConnectionError("Falló la recepción del mensaje\n");
    text.append(tmp_buf.begin(), tmp_buf.end());
  }
  return text;
}

void Socket::stop_sending() { shutdown(file_d, SHUT_WR); }

void Socket::stop() {
  shutdown(file_d, SHUT_RDWR);
  close(file_d);
}

Socket::~Socket() {}
