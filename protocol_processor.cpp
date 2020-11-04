#include "protocol_processor.h"

#include <iostream>
#include <string>
#include <vector>

void ProtocolProcessor::process(std::string msg) {
  std::vector<std::string> lines = protocol.get_lines(msg);
  start(lines);
}

void ProtocolProcessor::start(std::vector<std::string> lines) {
  bool body = false;
  protocol.set_command(lines[0]);
  for (size_t i = 1; i < lines.size(); i++) {
    std::string line = lines[i];
    if (body)
      protocol.set_body(line);
    else if (!line.length())
      body = true;
  }
}

void ProtocolProcessor::show_all() {
  std::string first_line = protocol.get_method() + " " +
                           protocol.get_resource() + " " +
                           protocol.get_protocol() + "\n";

  std::cout << first_line;
  std::cout << protocol.get_body() << "\n";
}

std::string ProtocolProcessor::get_method() { return protocol.get_method(); }
std::string ProtocolProcessor::get_body() { return protocol.get_body(); }
std::string ProtocolProcessor::get_resource() {
  return protocol.get_resource();
}
