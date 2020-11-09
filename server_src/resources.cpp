#include "resources.h"

Resources::Resources() {}

Resources::~Resources() {}

void Resources::add_resource(const std::string& resource,
                             const std::string& body) {
  std::unique_lock<std::mutex> lock(m);
  resources[resource] = body;
}

std::string Resources::get_resource(const std::string& resource) {
  std::unique_lock<std::mutex> lock(m);
  if (resources.find(resource) != resources.end()) {
    return resources.at(resource);
  }
  return "";
}
