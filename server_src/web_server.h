#ifndef WEB_SERVER
#define WEB_SERVER

#include <string>

#include "../common_src/socket.h"
#include "accepter.h"
#include "file_reader.h"
#include "resources.h"

class WebServer {
 private:
  Resources resources;
  Socket sv;
  Accepter acceptator;
  FileReader file_reader;

 public:
  /* Init del servidor web. Recibe el puerto en donde se hosteara y el nombre
  del archivo que contiene el contenido root */
  WebServer(const char* port, const std::string& file_name);

  /* Comienza a funcion el servidor */
  void operator()();

  /* Se prohíben las copias y los movimientos */
  WebServer& operator=(const WebServer&) = delete;
  WebServer& operator=(WebServer&&) = delete;
  WebServer(const WebServer&) = delete;
  WebServer(WebServer&&) = delete;

  /* Destructor del servidor web*/
  ~WebServer();
};

#endif  // WEB_SERVER
