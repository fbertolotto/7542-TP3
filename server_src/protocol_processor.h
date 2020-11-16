#ifndef PROTOCOL_PROCESSOR
#define PROTOCOL_PROCESSOR

#include <string>
#include <vector>

class ProtocolProcessor {
 private:
  std::vector<std::string> commands;
  std::string body;

  /* Devuelve un vector con las palabras separadas del mensaje especificadas por
  el delimitador. El parametro booleano se utiliza para determinar si las lineas
  vacias sonignoradas o agregadas */
  std::vector<std::string> split(std::string msg, char delimiter,
                                 bool ignore_empty);
  /* Comienza el procesado de las lineas */
  void start(std::vector<std::string> lines);
  /* Guarda en comandos el comando especifico */
  void set_command(const std::string& command);
  /* Guarda el body del protocol */
  void set_body(const std::string& body);
  /* Recibe un mensaje y devuelve un vector con cada linea de ese mensaje */
  std::vector<std::string> get_lines(const std::string& msg);

 public:
  /* Procesa el mensaje recibido */
  void process(const std::string& msg);

  /* Devuelve un string con el metodo */
  std::string get_method();

  /* Devuelve un string con el recurso */
  std::string get_resource();

  /* Devuelve un string con el protocolo */
  std::string get_protocol();

  /* Devuelve un string con el body */
  std::string get_body();
};

#endif  // PROTOCOL_PROCESSOR
