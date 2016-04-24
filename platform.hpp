#pragma once

#include <SFML/Graphics.hpp>

class Platform
{
public:
  Platform(sf::Vector2f pos, sf::Texture tex);
  void draw(sf::RenderWindow &window);
  sf::Sprite sprite;
};
