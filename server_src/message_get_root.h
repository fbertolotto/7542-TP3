#ifndef MESSAGE_GET_ROOT
#define MESSAGE_GET_ROOT

#include <string>

#include "message.h"

class MessageGetRoot : public Message {
 public:
  explicit MessageGetRoot(const std::string& msg);
  std::string get_message() override;
  ~MessageGetRoot();
};

#endif  // MESSAGE_GET_ROOT
