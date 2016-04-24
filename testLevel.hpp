#pragma once

#include <SFML/Graphics.hpp>
#include "platform.hpp"
#include "TextureManager.hpp"
#include <iostream>

class testLevel
{
public:
  testLevel();
  ~testLevel();
  void draw(sf::RenderWindow &window);
private:
  Platform* testPlatform;
  sf::Sprite background;
  TextureManager texMan;
  sf::Texture backgroundTex, platformTex;
};
