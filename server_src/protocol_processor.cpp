#include "protocol_processor.h"

#include <iostream>
#include <string>
#include <vector>

void ProtocolProcessor::process(std::string msg) {
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
                                                  std::string delimiter,
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

void ProtocolProcessor::set_command(std::string command) {
  commands = split(command, " ", true);
}

void ProtocolProcessor::set_body(std::string body) {
  if (this->body.size() != 0) this->body += "\n";
  this->body += body;
}

std::vector<std::string> ProtocolProcessor::get_lines(std::string msg) {
  return split(msg, "\n", false);
}
