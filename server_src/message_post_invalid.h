#ifndef MESSAGE_POST_INVALID
#define MESSAGE_POST_INVALID

#include <string>

#include "message.h"

class MessagePostInvalid : public Message {
 public:
  explicit MessagePostInvalid(const std::string& msg);
  std::string get_message() override;
  ~MessagePostInvalid();
};

#endif  // MESSAGE_POST_INVALID
