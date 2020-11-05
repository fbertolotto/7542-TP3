#ifndef RESOURCES
#define RESOURCES

#include <map>
#include <mutex>
#include <string>

class Resources {
 private:
  std::map<std::string, std::string> resources;
  std::mutex m;

 public:
  void add_resource(std::string resource, std::string body);
  std::string get_resource(std::string resource);
  void show_all();
};

#endif