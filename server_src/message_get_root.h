#ifndef MESSAGE_GET_ROOT
#define MESSAGE_GET_ROOT

#include <string>

#include "message.h"

class MessageGetRoot : public Message {
 public:
  MessageGetRoot(std::string msg) { text = msg; }
  std::string get_message() override {
    return "HTTP 200 OK\nContent-Type: text/html\n\n";
  }
  ~MessageGetRoot() {}
};

#endif
