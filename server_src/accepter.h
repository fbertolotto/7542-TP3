#include <vector>

#include "client_handler.h"

class Accepter : public Thread {
 private:
  Socket& sv;
  Resources resources;
  std::vector<ClientHandler*> handlers;
  bool keep_accepting = true;
  void clear_finished();

 public:
  Accepter(Socket& sk);
  void run() override;
  void stop();
  ~Accepter();
};
