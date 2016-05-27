#pragma once

#include <SFML/Graphics.hpp>
#include "PhysicsComp.hpp"
#include "AnimatedSprite.h"
#include "AnimationComponent.hpp"

class Player
{
  public:
    enum powerState {none, fire, web, stone};
    Player();
    void draw(sf::RenderWindow& window);
    void update(sf::Time deltaTime);
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f pos);
    void setNewLevel(std::string name);
    void shoot();

    void enableWebs()
    {
      webAble = true;
    }
    void enableFire()
    {
      fireAble = true;
    }
    void enableStone()
    {
      stoneAble = true;
    }
  private:
    bool inAction;
    bool webAble, fireAble, stoneAble;
    powerState currentPower;
    PlayerAnimation playerSprite;
    sf::Texture playerTexture;
    PhysicsComponent phys;
    AnimatedSprite webBullet;
    Animation webAnim;
    sf::Texture webTexture;
    sf::Clock actionTimer;
};
