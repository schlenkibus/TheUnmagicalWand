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
  sf::Texture& getRef(const std::string& texture)
  {
    return this->textures.at(texture);
  }
  ~TextureManager();
private:
  std::map<std::string, sf::Texture> textures;
};
