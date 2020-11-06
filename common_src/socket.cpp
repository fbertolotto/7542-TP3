#include "socket.h"

#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

Socket::Socket() {}

/* Servidor */
Socket::Socket(const char* port, int queue) {
  struct addrinfo hints;
  _set_net_flags(&hints);
  getaddrinfo(NULL, port, &hints, &info);
  _start();
  _bind();
  _listen(queue);
  freeaddrinfo(info);
}

/* Cliente */
Socket::Socket(const char* host, const char* port) {
  struct addrinfo hints;
  _set_net_flags(&hints);
  getaddrinfo(host, port, &hints, &info);
  _start();
}

Socket::Socket(Socket&& other) { this->file_d = std::move(other.file_d); }

Socket& Socket::operator=(Socket&& other) {
  this->file_d = std::move(other.file_d);
  other.file_d = -1;
  return *this;
}

void Socket::_set_net_flags(struct addrinfo* hints) {
  memset(hints, 0, sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM;
  hints->ai_flags = 0;
}

int Socket::_start() {
  struct addrinfo* data;
  int tmp_sk = -1;
  for (data = info; data != NULL; data = data->ai_next) {
    tmp_sk = socket(data->ai_family, data->ai_socktype, data->ai_protocol);
    if (tmp_sk != -1) break;
  }
  if (tmp_sk == -1) return 1;
  int val = 1;
  file_d = tmp_sk;
  setsockopt(file_d, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
  return 0;
}

int Socket::_bind() {
  int res = bind(file_d, info->ai_addr, info->ai_addrlen);
  if (res == -1) return 1;
  return 0;
}

int Socket::_listen(int queue_size) {
  int res = listen(file_d, queue_size);
  if (res == -1) return 1;
  return 0;
}

int Socket::accept_client(Socket& client) {
  struct sockaddr adrr;
  socklen_t adrrlen = (socklen_t)sizeof(adrr);
  int res = accept(file_d, &adrr, &adrrlen);
  if (res == -1) return 1;
  client.file_d = res;
  return 0;
}

int Socket::connect_to_sv() {
  struct addrinfo* sv;
  int connected = -1;
  for (sv = info; sv != NULL; sv = sv->ai_next) {
    if (_start() == 0) {
      connected = connect(file_d, sv->ai_addr, sv->ai_addrlen);
      if (connected != -1) break;
    }
  }
  freeaddrinfo(info);
  if (connected == -1) return 1;
  return 0;
}

int Socket::send_msg(std::string msg, int len) {
  int total_bytes = 0;
  while (total_bytes < len) {
    int bytes =
        send(file_d, &msg[total_bytes], len - total_bytes, MSG_NOSIGNAL);
    if (bytes == -1) return 1;
    total_bytes += bytes;
  }
  return 0;
}

int Socket::recv_msg(std::string& buffer) {
  int bytes = 1;
  while (bytes > 0) {
    std::vector<char> tmp_buf(64);
    bytes = recv(file_d, tmp_buf.data(), tmp_buf.size(), 0);
    if (bytes == -1) return 1;
    buffer.append(tmp_buf.begin(), tmp_buf.end());
  }
  return 0;
}

void Socket::stop_sending() { shutdown(file_d, SHUT_WR); }

Socket::~Socket() {
  if (file_d != -1) {
    close(file_d);
  }
}