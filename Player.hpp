#pragma once

#include <SFML/Graphics.hpp>
#include "PhysicsComp.hpp"

class Player
{
  public:
    Player() : phys(sf::Vector2f(100, 100), sf::Vector2f(40, 100))
    {
        playerTexture.loadFromFile("art/player/normal1.png");
        playerSprite.setPosition(100, 100);
        playerSprite.setTexture(playerTexture);
    };
    void draw(sf::RenderWindow& window);
  private:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    PhysicsComponent phys;
};
