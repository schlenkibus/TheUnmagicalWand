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
  std::string getLineWithTerm(std::string searchTerm); //Returns "0" if term was not found
  std::string getLineWithTerms(std::string term1, std::string term2); //Returns "0" if Terms were not found
  unsigned int getMatches(std::string term);
  unsigned int getLines();
  std::string getLine(unsigned int number);
  std::string getLineWithMatch(unsigned int number, std::string term);
};
