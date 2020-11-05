#include "message_handler.h"

#include <string>

Message* MessageHandler::create_message(std::string method,
                                        std::string resource,
                                        Resources& resources) {
  /* GET ROOT */
  if (method == "GET" && resource == "/") return new MessageGetRoot("Hola");

  /* GET RECURSO */
  else if (method == "GET" && resource != "/") {
    std::string body = resources.get_resource(resource);
    if (body.size() == 0)
      return new MessageGetInvalid("");
    else
      return new MessageGetValid(body);

    /* POST ROOT */
  } else if (method == "POST" && resource == "/") {
    return new MessagePostInvalid("");
  } else {
    return new MessageInvalid("");
  }
}