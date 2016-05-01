#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>
#include <iostream>

class TextureManager
{
public:
  sf::Texture getTexture(std::string texName);
  ~TextureManager();
private:
  std::map<std::string, sf::Texture> textures;
};
