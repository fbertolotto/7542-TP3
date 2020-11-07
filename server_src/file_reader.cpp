#include "file_reader.h"

#include <utility>

FileReader::FileReader(const std::string& file_name) {
  this->file.open(file_name);
}

std::string FileReader::read_all() {
  std::stringstream text;
  std::string buffer;
  while (getline(file, buffer)) text << buffer << "\n";
  return text.str();
}

FileReader& FileReader::operator=(FileReader&& other) {
  this->file = std::move(other.file);
  return *this;
}

FileReader::~FileReader() {
  if (file.is_open()) file.close();
}
