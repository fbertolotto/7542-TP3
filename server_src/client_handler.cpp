#include "client_handler.h"

#include <sstream>
#include <string>
#include <utility>

#define RECV_BUFFER_LEN 64

ClientHandler::ClientHandler(Socket client, Resources& res)
    : sk(std::move(client)), resources(res), finished(false) {}

bool ClientHandler::finish() { return finished; }

void ClientHandler::run() {
  std::stringstream text;
  char buffer[RECV_BUFFER_LEN];
  int bytes;
  while ((bytes = sk.recv_msg(buffer, RECV_BUFFER_LEN)) != 0) {
    for (int i = 0; i < bytes; i++) {
      text << buffer[i];
    }
  }
  const std::string msg = text.str();
  pp.process(msg);
  show_command();
  execute_method();
  finished = true;
}

void ClientHandler::execute_method() {
  std::string method = pp.get_method();
  std::string resource = pp.get_resource();

  /* POST RECURSO */
  std::string response;
  if (method == "POST" && resource != "/")
    resources.add_resource(resource, pp.get_body());

  Message* msg = mh.create_message(method, resource, resources);
  response = msg->get_message();
  delete msg;
  sk.send_msg(response.c_str(), response.size());
  sk.stop_sending();
}

void ClientHandler::show_command() {
  std::stringstream msg;
  msg << pp.get_method() << " " << pp.get_resource() << " " << pp.get_protocol()
      << "\n";
  std::cout << msg.str();
}

ClientHandler::~ClientHandler() {}
