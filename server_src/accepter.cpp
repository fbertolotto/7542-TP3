#include "accepter.h"

#include <algorithm>

Accepter::Accepter(Socket& sk) : sv(sk), keep_accepting(true) {}

void Accepter::run() {
  while (keep_accepting) {
    Socket client = Socket();
    if (sv.accept_client(client)) continue;
    ClientHandler* handler = new ClientHandler(client, resources);
    handlers.push_back(handler);
    handler->start();
    clear_finished();
  }
}

void Accepter::clear_finished() {
  for (auto& handler : handlers) {
    if (handler->finish()) {
      handler->join();
      delete handler;
      auto position = std::find(handlers.begin(), handlers.end(), handler);
      handlers.erase(position);
    }
  }
}

void Accepter::stop() {
  keep_accepting = false;
  sv.stop();
}

Accepter::~Accepter() {
  for (auto& handler : handlers) {
    handler->stop();
    handler->join();
    delete handler;
  }
}
