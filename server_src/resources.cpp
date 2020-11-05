#include "resources.h"

#include <iostream>

#include "lock.h"

void Resources::add_resource(std::string resource, std::string body) {
  Lock M(m);
  resources[resource] = body;
}

std::string Resources::get_resource(std::string resource) {
  Lock M(m);
  if (resources.find(resource) != resources.end()) {
    return resources.at(resource);
  }
  return "";
}

void Resources::show_all() {
  for (auto& i : resources) {
    std::cout << i.first << " : \n" << i.second << "\n";
  }
}
