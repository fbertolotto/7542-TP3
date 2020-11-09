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
  /* Init de los recursos */
  Resources();

  /* Agrega un recurso. Recibe el nombre del recurso y el cuerpo del mismo */
  void add_resource(const std::string& resource, const std::string& body);

  /* Devuelve un string con el contenido del recurso, en caso de no existir
  devuelve un string vacio */
  std::string get_resource(const std::string& resource);

  /* Se prohíben las copias y los movimientos */
  Resources& operator=(const Resources&) = delete;
  Resources& operator=(Resources&&) = delete;
  Resources(const Resources&) = delete;
  Resources(Resources&&) = delete;

  /* Destructor de los recursos */
  ~Resources();
};

#endif  // RESOURCES
