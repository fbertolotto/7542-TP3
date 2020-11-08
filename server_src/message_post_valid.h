#ifndef MESSAGE_POST_VALID
#define MESSAGE_POST_VALID

#include <string>

#include "message.h"

class MessagePostValid : public Message {
 public:
  explicit MessagePostValid(const std::string& msg);
  std::string get_message() override;
  ~MessagePostValid();
};

#endif  // MESSAGE_POST_VALID
