#include "protocol_processor.h"
#include "resources.h"
#include "socket.h"

class ClientHandler {
 private:
  Socket& sk;
  Resources& resources;
  ProtocolProcessor pp;

 public:
  ClientHandler(Socket& client, Resources& res);
  void run();
};