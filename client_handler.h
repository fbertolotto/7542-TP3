#include "protocol_processor.h"
#include "resources.h"
#include "socket.h"

class ClientHandler {
 private:
  Socket& sk;
  Resources& resources;
  ProtocolProcessor pp;
  bool validate();
  void execute_method();
  void send_to_client(std::string msg);

 public:
  ClientHandler(Socket& client, Resources& res);
  void run();
};