#include "message_get_root.h"

#include <string>

MessageGetRoot::MessageGetRoot(std::string msg) { text = msg; }

std::string MessageGetRoot::get_message() {
  return "HTTP 200 OK\nContent-Type: text/html\n\n";
}
MessageGetRoot::~MessageGetRoot() {}
