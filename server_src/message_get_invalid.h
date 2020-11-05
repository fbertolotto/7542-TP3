#ifndef MESSAGE_GET_INVALID
#define MESSAGE_GET_INVALID

#include <string>

#include "message.h"

class MessageGetInvalid : public Message {
 public:
  MessageGetInvalid(std::string msg) { text = msg; }
  std::string get_message() override { return "HTTP 404 NOT FOUND\n\n"; }
  ~MessageGetInvalid() {}
};

#endif
