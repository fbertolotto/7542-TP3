#ifndef MESSAGE_GET_INVALID
#define MESSAGE_GET_INVALID

#include <string>

#include "message.h"

class MessageGetInvalid : public Message {
 public:
  explicit MessageGetInvalid(const std::string& msg);
  std::string get_message() override;
  ~MessageGetInvalid();
};

#endif  // MESSAGE_GET_INVALID
