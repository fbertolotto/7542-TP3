#include "message_get_invalid.h"

#include <string>

MessageGetInvalid::MessageGetInvalid(const std::string& msg) { text = msg; }

std::string MessageGetInvalid::get_message() {
  return "HTTP/1.1 404 NOT FOUND\n\n";
}

MessageGetInvalid::~MessageGetInvalid() {}
