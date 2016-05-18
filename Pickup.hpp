#pragma once

#include <SFML/Graphics.hpp>

class Pickup
{
public:
  enum pickupType {fire, stone, web, health};
  Pickup(sf::Vector2f pos, pickupType t)
  {
    active = true;
    sprite.setPosition(pos);
    if(t == fire)
      tex.loadFromFile("art/pickups/firePickup.png");
    if(t == web)
      tex.loadFromFile("art/pickups/webPickup.png");
    if(t == stone)
      tex.loadFromFile("art/pickups/stonePickup.png");

    type = t;

    sprite.setTexture(tex);
  };
  void setTexture(sf::Texture& tex)
  {
    sprite.setTexture(tex);
  };
  void draw(sf::RenderWindow& window)
  {
    if(active)
      window.draw(sprite);
  };
  sf::FloatRect getRect()
  {
    return sprite.getGlobalBounds();
  };
  void onPickup()
  {
    active = false;
  }
  bool getActive()
  {
    return active;
  }
  pickupType getType()
  {
    return type;
  }
private:
  sf::Sprite sprite;
  sf::Texture tex;
  pickupType type;
  bool active;
};
