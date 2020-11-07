#ifndef MESSAGE_GET_ROOT
#define MESSAGE_GET_ROOT

#include <string>

#include "message.h"

class MessageGetRoot : public Message {
 public:
  MessageGetRoot(std::string msg);
  std::string get_message() override;
  ~MessageGetRoot();
};

#endif
