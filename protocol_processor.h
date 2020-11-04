#include <string>

#include "protocol.h"

class ProtocolProcessor {
 private:
  Protocol protocol;
  std::string length_label = "Content-Length";
  void start(std::vector<std::string> lines);

 public:
  void process(std::string msg);
  void show_all();
};
