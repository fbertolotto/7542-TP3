#include "file_error.h"

#include <cstdarg>
#include <cstdio>

FileError::FileError(const char* format, ...) noexcept {
  va_list args;
  va_start(args, format);
  vsnprintf(msg, ERR_LEN, format, args);
  va_end(args);
}

const char* FileError::what() const noexcept { return msg; }

FileError::~FileError() {}
