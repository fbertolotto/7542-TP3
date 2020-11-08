#include "resources.h"

void Resources::add_resource(const std::string& resource,
                             const std::string& body) {
  Lock M(m);
  resources[resource] = body;
}

std::string Resources::get_resource(const std::string& resource) {
  Lock M(m);
  if (resources.find(resource) != resources.end()) {
    return resources.at(resource);
  }
  return "";
}
