#include "protocol.h"

std::vector<std::string> Protocol::split(std::string msg, std::string delimiter,
                                         bool ignore_empty) {
  size_t init = 0, delim_pos;
  std::vector<std::string> buffer;
  while ((delim_pos = msg.find(delimiter, init)) != std::string::npos) {
    std::string word = msg.substr(init, delim_pos - init);
    init = delim_pos + 1;
    if (word.length() == 0 and ignore_empty) continue;
    buffer.push_back(word);
  }
  buffer.push_back(msg.substr(init));
  return buffer;
}

void Protocol::set_command(std::string command) {
  commands = split(command, " ", true);
}

void Protocol::set_body(std::string body) { this->body += body + "\n"; }

void Protocol::set_length(std::string len) {
  std::vector<std::string> argv = split(len, " ", true);
  this->length = std::stol(argv[1]);
}

std::vector<std::string> Protocol::get_lines(std::string msg) {
  return split(msg, "\n", false);
}

std::string Protocol::get_method() { return commands[0]; }
std::string Protocol::get_resource() { return commands[1]; }
std::string Protocol::get_protocol() { return commands[2]; }
std::string Protocol::get_body() { return body; }
int Protocol::get_length() { return length; }
