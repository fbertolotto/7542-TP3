#include <string>

#include "protocol.h"

class ProtocolProcessor {
 private:
  Protocol protocol;
  void start(std::vector<std::string> lines);

 public:
  void process(std::string msg);
  void show_all();
  std::string get_method();
  std::string get_body();
  std::string get_resource();
};
