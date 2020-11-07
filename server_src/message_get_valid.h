#ifndef MESSAGE_GET_VALID
#define MESSAGE_GET_VALID

#include <string>

#include "message.h"

class MessageGetValid : public Message {
 public:
  MessageGetValid(std::string msg);
  std::string get_message() override;
  ~MessageGetValid();
};

#endif
