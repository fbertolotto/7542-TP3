#include <atomic>
#include <vector>

#include "client_handler.h"

class Accepter : public Thread {
 private:
  Socket& sv;
  Resources& resources;
  std::vector<ClientHandler*> handlers;
  std::atomic_bool keep_accepting;
  void clear_finished();

 public:
  Accepter(Socket& sk, Resources& rs);
  void run() override;
  void stop();
  ~Accepter();
};
