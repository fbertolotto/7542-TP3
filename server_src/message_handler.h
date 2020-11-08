#ifndef MESSAGE_HANDLER
#define MESSAGE_HANDLER

#include <string>

#include "message.h"
#include "message_get_invalid.h"
#include "message_get_root.h"
#include "message_get_valid.h"
#include "message_invalid.h"
#include "message_post_invalid.h"
#include "message_post_valid.h"
#include "resources.h"

class MessageHandler {
 public:
  MessageHandler() {}
  Message* create_message(std::string method, std::string resource,
                          Resources& resources);
  ~MessageHandler() {}
};

#endif  // MESSAGE_HANDLER
