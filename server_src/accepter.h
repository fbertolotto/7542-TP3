#include <vector>

#include "client_handler.h"

class Accepter : public Thread {
 private:
  Socket& sv;
  Resources resources;
  std::vector<ClientHandler*> handlers;
  bool alive = true;

 public:
  Accepter(Socket& sk);
  void run() override;
  ~Accepter();
};
