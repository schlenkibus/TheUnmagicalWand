#pragma once

#include <sstream>
#include <vector>
namespace StringTools
{
  void split(std::vector<std::string>& out, const std::string& in, char delim);

  std::string trim(const std::string& str, const std::string& whitespace = " \t");
};