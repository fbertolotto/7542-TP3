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

static bool is_null(ClientHandler* ch) { return !ch; }

void Accepter::clear_finished() {
  int i = 0;
  for (auto& handler : handlers) {
    if (handler->finish()) {
      handler->join();
      delete handler;
      handlers[i] = nullptr;
    }
    i++;
  }
  handlers.erase(std::remove_if(handlers.begin(), handlers.end(), is_null),
                 handlers.end());
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
