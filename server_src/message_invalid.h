#ifndef MESSAGE_INVALID
#define MESSAGE_INVALID

#include <string>

#include "message.h"

class MessageInvalid : public Message {
 public:
  explicit MessageInvalid(const std::string& msg);
  std::string get_message() override;
  ~MessageInvalid();
};

#endif  // MESSAGE_INVALID
