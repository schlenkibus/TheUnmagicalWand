#include "StringTools.h"

namespace StringTools
{
  void split(std::vector<std::string>& out, const std::string& in, char delim)
  {
    std::string token;
    std::istringstream tokenStream(in);
    while(std::getline(tokenStream, token, delim))
    {
      out.emplace_back(token);
    }
  }

  std::string trim(const std::string& str, const std::string& whitespace)
  {
    const auto strBegin = str.find_first_not_of(whitespace);
    if(strBegin == std::string::npos)
      return "";

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
  }
}