#ifndef CLIENT_HANDLER
#define CLIENT_HANDLER

#include <atomic>

#include "../common_src/socket.h"
#include "message_handler.h"
#include "protocol_processor.h"
#include "resources.h"
#include "thread.h"

class ClientHandler : public Thread {
 private:
  Socket sk;
  Resources& resources;
  ProtocolProcessor pp;
  MessageHandler mh;
  std::atomic_bool finished;
  void execute_method();
  void show_command();

 public:
  ClientHandler(Socket& client, Resources& res);
  void run();
  bool finish();
  void stop();
  ~ClientHandler();
};

#endif