#include "message_post_invalid.h"

#include <string>

MessagePostInvalid::MessagePostInvalid(std::string msg) { text = msg; }

std::string MessagePostInvalid::get_message() {
  return "HTTP 403 FORBIDDEN\n\n";
}

MessagePostInvalid::~MessagePostInvalid() {}
