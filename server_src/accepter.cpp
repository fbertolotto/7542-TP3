#include "accepter.h"

#include <algorithm>
#include <utility>

Accepter::Accepter(Socket& sk, Resources& rs)
    : sv(sk), resources(rs), keep_accepting(true) {}

void Accepter::run() {
  while (keep_accepting) {
    Socket client;
    try {
      sv.accept_client(client);
      ClientHandler* handler = new ClientHandler(std::move(client), resources);
      handlers.push_back(handler);
      handler->start();
    } catch (const ConnectionError& err) {
      continue;
    }
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
    handler->join();
    delete handler;
  }
}
