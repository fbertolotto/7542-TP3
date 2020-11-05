#ifndef MESSAGE_POST_INVALID
#define MESSAGE_POST_INVALID

#include <string>

#include "message.h"

class MessagePostInvalid : public Message {
 public:
  MessagePostInvalid(std::string msg) { text = msg; }
  std::string get_message() override { return "HTTP 403 FORBIDDEN\n\n"; }
  ~MessagePostInvalid() {}
};

#endif
