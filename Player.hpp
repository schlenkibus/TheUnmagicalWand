#pragma once

#include <SFML/Graphics.hpp>
#include "PhysicsComp.hpp"

class Player
{
  public:
    Player() : phys(sf::Vector2f(100, 100), sf::Vector2f(113, 128))
    {
        playerTexture.loadFromFile("art/player/normal1.png");
        playerSprite.setPosition(100, 100);
        playerSprite.setTexture(playerTexture);
        playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, 0);
    };
    void draw(sf::RenderWindow& window);
    void update()
    {
        playerSprite.setPosition(phys.update());
    };
  private:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    PhysicsComponent phys;
};
