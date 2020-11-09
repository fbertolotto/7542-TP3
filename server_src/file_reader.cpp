#include "file_reader.h"

#include <utility>

FileReader::FileReader(const std::string& file_name) {
  this->file.open(file_name);
  if (!this->file.is_open()) throw FileError("Falló la apertura del archivo");
}

std::string FileReader::read_all() {
  std::stringstream text;
  std::string buffer;
  while (getline(file, buffer)) text << buffer << "\n";
  return text.str();
}

FileReader::~FileReader() {
  if (file.is_open()) file.close();
}
