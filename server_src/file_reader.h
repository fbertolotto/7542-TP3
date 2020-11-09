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

  /* Se prohíben las copias y los movimientos */
  FileReader(const FileReader&) = delete;
  FileReader(FileReader&&) = delete;
  FileReader& operator=(const FileReader&) = delete;
  FileReader& operator=(FileReader&&) = delete;

  /* Destructor del lector de archivos. */
  ~FileReader();
};

#endif  // FILE_READER
