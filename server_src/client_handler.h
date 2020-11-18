#ifndef CLIENT_HANDLER
#define CLIENT_HANDLER

#include <atomic>

#include "../common_src/protocol.h"
#include "../common_src/socket.h"
#include "message_handler.h"
#include "protocol_processor.h"
#include "resources.h"
#include "thread.h"

class ClientHandler : public Thread {
 private:
  Socket sk;
  Resources& resources;
  ProtocolProcessor pp;
  Protocol protocol;
  MessageHandler mh;
  std::atomic_bool finished;
  /* Ejecuta el comando recibido */
  void execute_method();
  /* Muestra por salida estandar el comando recibido */
  void show_command();

 public:
  /* Init del handler de clientes, recibe el socket en donde fue aceptador
  el cliente y una referencia a los recursos compartidos del servidor */
  ClientHandler(Socket client, Resources& res);

  /* Ejecuta el parseo del mensaje y genera la respuesta */
  void run() override;

  /* Devuelve True si el handler finalizo su ejecucuion y false en caso
  de seguir procesando */
  bool finish();

  /* Finaliza el handler */
  void stop();

  /* Se prohíben las copias y los movimientos */
  ClientHandler& operator=(const ClientHandler&) = delete;
  ClientHandler& operator=(ClientHandler&&) = delete;
  ClientHandler(const ClientHandler&) = delete;
  ClientHandler(ClientHandler&&) = delete;

  /* Destructor del handler */
  ~ClientHandler();
};

#endif  // CLIENT_HANDLER
