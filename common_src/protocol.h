#ifndef PROTOCOL
#define PROTOCOL

#include <string>

#include "socket.h"

class Protocol {
 private:
  Socket& sk;

 public:
  /* Init del protocolo, recibe el socket por donde recibirá
  la información */
  Protocol(Socket& socket);

  /* Devuelve una cadena con la información completa */
  std::string get_full_msg();

  /* Destructor del protocolo */
  ~Protocol();
};

#endif  // PROTOCOL
