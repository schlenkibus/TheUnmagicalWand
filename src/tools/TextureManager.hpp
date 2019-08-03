#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>
#include <iostream>

class TextureManager
{
 public:
  static TextureManager& get();
  sf::Texture& getTexture(const std::string& texName);

 private:
  std::map<std::string, sf::Texture> m_textures;
};
