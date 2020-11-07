#include "message_get_invalid.h"

#include <string>

MessageGetInvalid::MessageGetInvalid(std::string msg) { text = msg; }

std::string MessageGetInvalidget_message() { return "HTTP 404 NOT FOUND\n\n"; }

MessageGetInvalid::~MessageGetInvalid() {}
