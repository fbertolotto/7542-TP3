#include "message_post_valid.h"

#include <string>

MessagePostValid::MessagePostValid(std::string msg) { text = msg; }

std::string MessagePostValid::get_message() {
  return ("HTTP/1.1 200 OK\n\n" + text);
}

MessagePostValid::~MessagePostValid() {}
