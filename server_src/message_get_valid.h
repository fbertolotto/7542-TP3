#ifndef MESSAGE_GET_VALID
#define MESSAGE_GET_VALID

#include <string>

#include "message.h"

class MessageGetValid : public Message {
 public:
  MessageGetValid(std::string msg) { text = msg; }
  std::string get_message() override { return ("HTTP 200 OK\n\n" + text); }
  ~MessageGetValid() {}
};

#endif
