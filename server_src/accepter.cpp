#include "accepter.h"

#include <algorithm>

Accepter::Accepter(Socket& sk) : sv(sk) {}

void Accepter::run() {
  do {
    Socket client = Socket();
    sv.accept_client(client);
    ClientHandler* handler = new ClientHandler(client, resources);
    handlers.push_back(handler);
    handler->start();

    for (auto handler : handlers) {
      if (handler->finish()) {
        handler->join();
        delete handler;
        auto position = std::find(handlers.begin(), handlers.end(), handler);
        handlers.erase(position);
      }
    }
  } while (true);
}

Accepter::~Accepter() {}