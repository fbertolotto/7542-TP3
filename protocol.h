#include <string>
#include <vector>

class Protocol {
 private:
  std::vector<std::string> commands;
  int length = 0;
  std::string body;
  std::vector<std::string> split(std::string msg, std::string delimiter,
                                 bool ignore_empty);

 public:
  void set_command(std::string command);
  void set_length(std::string len);
  void set_body(std::string body);
  int get_length();
  std::vector<std::string> get_lines(std::string msg);
  std::string get_method();
  std::string get_resource();
  std::string get_protocol();
  std::string get_body();
};