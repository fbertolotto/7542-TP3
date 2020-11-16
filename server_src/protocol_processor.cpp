#include "protocol_processor.h"

#include <sstream>
#include <string>
#include <vector>

void ProtocolProcessor::process(const std::string& msg) {
  std::vector<std::string> lines = get_lines(msg);
  start(lines);
}

void ProtocolProcessor::start(std::vector<std::string> lines) {
  bool body = false;
  set_command(lines[0]);
  for (size_t i = 1; i < lines.size(); i++) {
    std::string line = lines[i];
    if (body && commands[0] == "POST")
      set_body(line);
    else if (!line.length())
      body = true;
  }
}

std::string ProtocolProcessor::get_method() { return commands[0]; }
std::string ProtocolProcessor::get_resource() { return commands[1]; }
std::string ProtocolProcessor::get_protocol() { return commands[2]; }
std::string ProtocolProcessor::get_body() { return body; }

std::vector<std::string> ProtocolProcessor::split(std::string msg,
                                                  char delimiter,
                                                  bool ignore_empty) {
  std::vector<std::string> buffer;
  std::stringstream ss(msg);
  std::string s;
  while (std::getline(ss, s, delimiter)) {
    if (ignore_empty && s.size() == 0) continue;
    buffer.push_back(s);
  }
  return buffer;
}

void ProtocolProcessor::set_command(const std::string& command) {
  commands = split(command, ' ', true);
}

void ProtocolProcessor::set_body(const std::string& body) {
  if (this->body.size() != 0) this->body += "\n";
  this->body += body;
}

std::vector<std::string> ProtocolProcessor::get_lines(const std::string& msg) {
  return split(msg, '\n', false);
}
