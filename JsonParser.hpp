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
  JsonParser(std::string fileInput);
  ~JsonParser();
  bool searchForTerm(std::string searchTerm);
  bool searchForTerms(std::string term1, std::string term2);
  string getLineWithTerm(std::string searchTerm); //Returns -1 if term was not found
  string getLineWithTerms(std::string term1, std::string term2); //Returns -1 if Term was not found
};
