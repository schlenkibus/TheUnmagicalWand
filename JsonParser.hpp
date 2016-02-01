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
  bool searchForTerm(std::string searchTerm);
  bool searchForTerms(std::string term1, std::string term2);
};
