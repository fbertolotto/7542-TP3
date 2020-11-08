#ifndef CONNECTION_ERROR
#define CONNECTION_ERROR

#include <typeinfo>

#define ERR_LEN 256

class ConnectionError : public std::exception {
 private:
  char msg[ERR_LEN];

 public:
  explicit ConnectionError(const char* format, ...) noexcept;
  virtual const char* what() const noexcept;
  virtual ~ConnectionError() noexcept;
};

#endif
