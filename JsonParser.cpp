#include "JsonParser.hpp"

JsonParser::JsonParser(std::string fileName)
{
  std::string path;
  path = "json/";
  path += fileName;
  stream.open(path.c_str(), std::fstream::in);
  std::string temp;
  while(std::getline(stream, temp))
  {
    lines.push_back(temp);
  }
}

JsonParser::~JsonParser()
{
  stream.close();
}

bool JsonParser::searchForTerm(std::string searchTerm)
{
  for(unsigned int i = 0; i < lines.size(); i++)
  {
    if(lines[i].find(searchTerm) != std::string::npos)
    {
      return true;
    }
  }
  return false;
}

bool JsonParser::searchForTerms(std::string term1, std::string term2)
{
  for(unsigned int i = 0; i < lines.size(); i++)
  {
    if(lines[i].find(term1) != std::string::npos
    && lines[i].find(term2) != std::string::npos)
    {
      return true;
    }
  }
  return false;
}
