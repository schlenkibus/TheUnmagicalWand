#include "SFML/Graphics.hpp"
#pragma once

class MenuHelp
{
private:
  sf::Sprite background, controls, anyKey;
  sf::Texture backTex, contrTex, anyTex;
  bool shouldBeActive;
public:
  MenuHelp();
  void update();
  void render(sf::RenderWindow& window);
  bool getActive();
  void setActive();
};
