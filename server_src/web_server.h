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
  WebServer(const char* port, const std::string& file_name);
  void operator()();
  ~WebServer();
};

#endif  // WEB_SERVER
