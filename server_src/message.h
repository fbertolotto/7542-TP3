#ifndef MESSAGE
#define MESSAGE

#include <string>

/* Clase abstracta Mensaje */
class Message {
 protected:
  std::string text;

 public:
  /* Init del mensaje */
  Message() {}

  /* Devuelve el mensaje contenido */
  virtual std::string get_message() = 0;

  /* Destructor del mensaje */
  virtual ~Message() {}
};

#endif  // MESSAGE
