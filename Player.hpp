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
    void hitFire();
    void hitStone();
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
    bool dealingDamage()
    {
      return dealsDamage;
    }
    void dealDamage(int d);
    void destroy();
    sf::FloatRect getRect()
    {
      return playerSprite.getSprite().getGlobalBounds();
    }
    sf::FloatRect getProjectile()
    {
      return webBullet.getGlobalBounds();
    }
    bool isBulletActive()
    {
      return bulletActive;
    }
  private:
    bool inAction, bulletActive;
    bool dealsDamage;
    bool webAble, fireAble, stoneAble;
    int health;
    powerState currentPower;
    PlayerAnimation playerSprite;
    sf::Texture playerTexture;
    PhysicsComponent phys;
    AnimatedSprite webBullet;
    Animation webAnim;
    sf::Texture webTexture;
    sf::Clock actionTimer, damageTimer, animTimer;
    sf::Vector2f webVector;
    //Private Methods
    void flicker();
};
