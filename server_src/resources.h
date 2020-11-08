#ifndef RESOURCES
#define RESOURCES

#include <map>
#include <string>

#include "lock.h"

class Resources {
 private:
  std::map<std::string, std::string> resources;
  std::mutex m;

 public:
  void add_resource(const std::string& resource, const std::string& body);
  std::string get_resource(const std::string& resource);
};

#endif  // RESOURCES
