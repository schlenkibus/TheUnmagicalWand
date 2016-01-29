#include <SFML/Graphics.hpp>

#pragma once

class SplashScreen
{
private:
  sf::Texture Logo;
  sf::Sprite Sprite;
public:
  SplashScreen();
  void update();
  void render(sf::RenderWindow& window);
};
