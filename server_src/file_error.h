#ifndef FILE_ERROR
#define FILE_ERROR

#include <typeinfo>

#define ERR_LEN 256

class FileError : public std::exception {
 private:
  char msg[ERR_LEN];

 public:
  explicit FileError(const char* format, ...) noexcept;
  virtual const char* what() const noexcept;
  virtual ~FileError() noexcept;
};

#endif  // FILE_ERROR
