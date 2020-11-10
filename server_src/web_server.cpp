#include "web_server.h"

#include <iostream>
#include <string>

#define QUEUE_SIZE 10

WebServer::WebServer(const char* port, const std::string& file_name)
    : sv(port, QUEUE_SIZE), acceptator(sv, resources), file_reader(file_name) {
  std::string file_content = file_reader.read_all();
  resources.add_resource("/", file_content);
}

void WebServer::operator()() { acceptator.start(); }

WebServer::~WebServer() {
  acceptator.stop();
  acceptator.join();
}
