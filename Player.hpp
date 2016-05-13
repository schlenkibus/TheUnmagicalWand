#pragma once

#include <SFML/Graphics.hpp>
#include "PhysicsComp.hpp"
#include "AnimatedSprite.h"
#include "AnimationComponent.hpp"

class Player
{
  public:
    Player() : phys(sf::Vector2f(100, 100), sf::Vector2f(33, 100))
    {
        playerSprite.setPosition(sf::Vector2f(100, 100));
        playerSprite.setOrigin(sf::Vector2f(playerSprite.getSprite().getLocalBounds().width / 2, 0.0f));
        phys.setCurrentLevelAndLoadData("level1.json");
    };
    void draw(sf::RenderWindow& window);
    void update(sf::Time deltaTime)
    {
      playerSprite.setPosition(phys.update());
      playerSprite.update(deltaTime);
    };
  private:
    PlayerAnimation playerSprite;
    sf::Texture playerTexture;
    PhysicsComponent phys;
};
