#include "JsonParser.hpp"

JsonParser::JsonParser(std::string fileName)
{
  std::string path;
  path = "json/";
  path += fileName;
  stream.open(path.c_str(), std::fstream::in);
  while(!stream.eof())
  {
    //lines.emplace_back(stream.getline());
  }
}

JsonParser::~JsonParser()
{
  stream.close();
}

void InterpretLine(std::string searchTerm)
{
  /*for(int i = 0; i < lines.size(); i++)
  {
    if(lines[i].find(searchTerm) != std::string::npos)
    {

    }
  }*/
}
