#ifndef MESSAGE
#define MESSAGE

#include <string>

class Message {
 protected:
  std::string text;

 public:
  Message() {}
  virtual std::string get_message() = 0;
  virtual ~Message() {}
};

#endif