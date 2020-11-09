#ifndef ACCEPTER
#define ACCEPTER

#include <atomic>
#include <vector>

#include "client_handler.h"

class Accepter : public Thread {
 private:
  Socket& sv;
  Resources& resources;
  std::vector<ClientHandler*> handlers;
  std::atomic_bool keep_accepting;
  /* Elimina los peers que ya hayan finalizado la ejecución */
  void clear_finished();

 public:
  /* Init del aceptador, recibe el socket servidor y los recursos compartidos */
  Accepter(Socket& sk, Resources& rs);

  /* Ejecuta el proceso de aceptar e interactuar con los usuarios */
  void run() override;

  /* Finaliza la ejecución. Se deja de aceptar nuevos clientes y se finalizan
  los actualmente activos */
  void stop();

  /* Se prohíben las copias y los movimientos */
  Accepter& operator=(const Accepter&) = delete;
  Accepter& operator=(Accepter&&) = delete;
  Accepter(const Accepter&) = delete;
  Accepter(Accepter&&) = delete;

  /* Destructor del aceptador */
  ~Accepter();
};

#endif  // ACCEPTER
