#include "message_invalid.h"

#include <string>

MessageInvalid::MessageInvalid(std::string msg) { text = msg; }

std::string MessageInvalid::get_message() {
  return "HTTP 405 METHOD NOT ALLOWED\n\n";
}

MessageInvalid::~MessageInvalid() {}
