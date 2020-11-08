#ifndef FILE_READER
#define FILE_READER

#include <bits/stdc++.h>

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

#include "file_error.h"

class FileReader {
 private:
  std::ifstream file;

 public:
  /* Init del lector de archivos */
  explicit FileReader(const std::string& file_name);

  /* Lee hasta EOF y lo guarda en el buffer. */
  std::string read_all();

  /* No se permiten constructores diferentes al default. */
  FileReader(const FileReader&) = delete;
  FileReader(FileReader&&) = delete;

  /* No se permiten copias por asignación. */
  FileReader& operator=(const FileReader&) = delete;

  /* Se permite por movimiento. */
  FileReader& operator=(FileReader&& other);

  /* Destructor del lector de archivos. */
  ~FileReader();
};

#endif  // FILE_READER
