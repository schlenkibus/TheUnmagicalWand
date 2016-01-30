#include <fstream>
#include <iostream>
#include <vector>

#pragma once

class JsonParser
{
private:
  std::fstream stream;
  std::vector<std::string> lines;
public:
  JsonParser(std::string fileName);
  ~JsonParser();
  void InterpretLine(std::string searchTerm);
};
