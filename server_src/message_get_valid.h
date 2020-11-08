#ifndef MESSAGE_GET_VALID
#define MESSAGE_GET_VALID

#include <string>

#include "message.h"

class MessageGetValid : public Message {
 public:
  explicit MessageGetValid(const std::string& msg);
  std::string get_message() override;
  ~MessageGetValid();
};

#endif  // MESSAGE_GET_VALID
