#include <string>

#include "../common_src/socket.h"

class Client {
 private:
  Socket sk;
  bool working = false;

 public:
  Client(char* host, char* port);
  void send_msg(std::string msg);
  void show_response();
  ~Client();
};
