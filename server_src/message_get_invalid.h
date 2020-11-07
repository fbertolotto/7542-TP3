#ifndef MESSAGE_GET_INVALID
#define MESSAGE_GET_INVALID

#include <string>

#include "message.h"

class MessageGetInvalid : public Message {
 public:
  MessageGetInvalid(std::string msg);
  std::string get_message() override;
  ~MessageGetInvalid();
};

#endif
