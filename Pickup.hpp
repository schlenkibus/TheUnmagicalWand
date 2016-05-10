#pragma once

#include <SFML/Graphics.hpp>

enum pickupType {fire, stone, web, health};

class Pickup
{
public:
  Pickup(sf::Vector2f pos, pickupType t)
  {
    sprite.setPosition(pos);
    type = t;
  };
  void setTexture(sf::Texture& tex)
  {
    sprite.setTexture(tex);
  };
  void draw(sf::RenderWindow& window)
  {
    window.draw(sprite);
  };
  sf::FloatRect getRect()
  {
    return sprite.getGlobalBounds();
  };
  void onPickup()
  {

  };
private:
  sf::Sprite sprite;
  pickupType type;
};
