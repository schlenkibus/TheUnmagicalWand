#pragma once

#include <SFML/Graphics.hpp>
#include "PhysicsComp.hpp"
#include "AnimatedSprite.h"
#include "AnimationComponent.hpp"

class Player
{
  public:
    enum powerState {none, fire, web, stone};
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
      if(phys.facesRight())
      {
        playerSprite.facesRight(true);
      }
      else
      {
        playerSprite.facesRight(false);
      }
      playerSprite.update(deltaTime);
    };
    sf::Vector2f getPosition()
    {
      return playerSprite.getSprite().getPosition();
    };
    void setPosition(sf::Vector2f pos)
    {
      playerSprite.setPosition(pos);
      phys.setPosition(pos);
    };
    void setNewLevel(std::string name)
    {
      phys.setCurrentLevelAndLoadData(name);
    };
  private:
    powerState currentPower;
    PlayerAnimation playerSprite;
    sf::Texture playerTexture;
    PhysicsComponent phys;
};
