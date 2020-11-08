#include "connection_error.h"

#include <cstdarg>
#include <cstdio>

ConnectionError::ConnectionError(const char* format, ...) noexcept {
  va_list args;
  va_start(args, format);
  vsnprintf(msg, ERR_LEN, format, args);
  va_end(args);
}

const char* ConnectionError::what() const noexcept { return msg; }

ConnectionError::~ConnectionError() {}
