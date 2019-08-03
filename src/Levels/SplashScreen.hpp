#include <SFML/Graphics.hpp>

#pragma once

class SplashScreen
{
private:
  sf::Texture Logo, KeyTex;
  sf::Sprite Sprite, KeySprite;
  bool shouldBeActive;
  sf::Clock timer;
  sf::Clock sizeTimer;
public:
  SplashScreen();
  void update();
  void render(sf::RenderWindow& window);
  bool getActive();
};
