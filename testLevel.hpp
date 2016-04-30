#pragma once

#include <SFML/Graphics.hpp>
#include "platform.hpp"
#include "TextureManager.hpp"
#include <iostream>
#include "JsonParser.hpp"
#include <list>
#include <memory>

class testLevel
{
public:
  testLevel();
  ~testLevel();
  void draw(sf::RenderWindow &window);
private:
  std::list<Platform> platforms;
  JsonParser* levelData;
  Platform* testPlatform;
  sf::Sprite background;
  TextureManager texMan;
  sf::Texture backgroundTex, platformTex;
};
