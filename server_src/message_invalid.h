#ifndef MESSAGE_INVALID
#define MESSAGE_INVALID

#include <string>

#include "message.h"

class MessageInvalid : public Message {
 public:
  MessageInvalid(std::string msg) { text = msg; }
  std::string get_message() override {
    return "HTTP 405 METHOD NOT ALLOWED\n\n";
  }
  ~MessageInvalid() {}
};

#endif
