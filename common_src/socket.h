#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstring>
#include <string>

class Socket {
 private:
  int file_d;
  struct addrinfo* info;
  void _set_net_flags(struct addrinfo* hints);
  int _start();
  int _bind();
  int _listen(int queue_size);
  void send_size(std::uint32_t len);
  std::uint32_t recv_size();

 public:
  Socket(const char* host, const char* port);
  Socket(const char* port, int queue);
  Socket();
  int accept_client(Socket& client);
  int connect_to_sv();
  int send_msg(std::string msg, std::uint32_t len);
  int recv_msg(std::string& buffer);
  ~Socket();
};