#include <string>
#include <vector>

class ProtocolProcessor {
 private:
  std::vector<std::string> commands;
  std::string body;
  std::vector<std::string> split(std::string msg, std::string delimiter,
                                 bool ignore_empty);
  void start(std::vector<std::string> lines);
  void set_command(std::string command);
  void set_body(std::string body);
  std::vector<std::string> get_lines(std::string msg);

 public:
  void process(std::string msg);
  void show_all();
  std::string get_method();
  std::string get_resource();
  std::string get_protocol();
  std::string get_body();
};
