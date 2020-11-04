#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <string>

class Socket {
 private:
  int file_d;
  struct addrinfo* info;
  void _set_net_flags(struct addrinfo* hints);
  int _start();
  int _bind();
  int _listen(int queue_size);

 public:
  Socket(const char* host, const char* port);
  Socket(const char* port, int queue);
  Socket();
  int accept_client(Socket& client);
  int connect_to_sv();
  int send_msg(std::string msg, int len);
  int recv_msg(std::string& buffer);
  ~Socket();
};