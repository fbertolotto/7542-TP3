#include "message_get_valid.h"

#include <string>

MessageGetValid::MessageGetValid(std::string msg) { text = msg; }

std::string MessageGetValid::get_message() {
  return ("HTTP/1.1 200 OK\n\n" + text);
}
MessageGetValid::~MessageGetValid() {}
