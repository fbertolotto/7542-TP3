#include "message_handler.h"

#include <string>

Message* MessageHandler::create_message(std::string method,
                                        std::string resource,
                                        Resources& resources) {
  /* GET ROOT */
  if (method == "GET" && resource == "/") {
    const std::string body = resources.get_resource(resource);
    return new MessageGetRoot(body);

  } else if (method == "GET") { /* GET RECURSO */
    std::string body = resources.get_resource(resource);
    if (body.size() == 0) {
      return new MessageGetInvalid("");
    } else {
      return new MessageGetValid(body);
    }

    /* POST ROOT */
  } else if (method == "POST" && resource == "/") {
    return new MessagePostInvalid("");

  } else if (method == "POST") {
    const std::string body = resources.get_resource(resource);
    return new MessagePostValid(body);
  } else {
    return new MessageInvalid(method);
  }
}
