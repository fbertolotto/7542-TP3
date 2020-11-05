#include "../common_src/socket.h"
#include "protocol_processor.h"
#include "resources.h"
#include "thread.h"

class ClientHandler : public Thread {
 private:
  Socket sk;
  Resources& resources;
  ProtocolProcessor pp;
  bool finished = false;
  void execute_method();
  void send_to_client(std::string msg);
  void show_command();

 public:
  ClientHandler(Socket& client, Resources& res);
  void run();
  bool finish() { return finished; }
  ~ClientHandler() {}
};