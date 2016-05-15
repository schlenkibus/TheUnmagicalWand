#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "AnimatedSprite.h"

class Boss
{
public:
  Boss()
  {
    alive = true;
  };
  ~Boss()
  {

  };
  virtual void update(sf::Time deltaTime)
  {

  };
  void draw(sf::RenderWindow& window)
  {
    window.draw(sprite);
  }
  bool getAlive()
  {

  };
  void dealDamage()
  {
    alive = false;
  };
protected:
  AnimatedSprite sprite;
  bool alive;
};

class BookBoss : public Boss
{
public:
  BookBoss(sf::Vector2f pos)
  {
    sprite.setPosition(pos);

    spritesheet.loadFromFile("art/mobs/boss/bookBoss.png");
    idle.setSpriteSheet(spritesheet);

    idle.addFrame(sf::IntRect(6, 27, 169, 202));
    idle.addFrame(sf::IntRect(182, 27, 168, 202));
    idle.addFrame(sf::IntRect(357, 27, 170, 202));
    idle.addFrame(sf::IntRect(535, 27, 170, 202));

    sprite.setAnimation(idle);
  };
  void update(sf::Time deltaTime)
  {
    sprite.update(deltaTime);
  };
private:
  Animation idle, damage, dead;
  sf::Texture spritesheet;
};

class KnifeBoss : public Boss
{
public:
  KnifeBoss(sf::Vector2f pos)
  {
    sprite.setPosition(pos);

    spritesheet.loadFromFile("art/mobs/boss/knifeBoss.png");
    idle.setSpriteSheet(spritesheet);

    idle.addFrame(sf::IntRect(27, 27, 200, 213));
    idle.addFrame(sf::IntRect(236, 27, 200, 213));
    idle.addFrame(sf::IntRect(462, 27, 200, 213));
    idle.addFrame(sf::IntRect(682, 27, 200, 213));

    sprite.setAnimation(idle);
  };
  void update(sf::Time deltaTime)
  {
    sprite.update(deltaTime);
  };
private:
  Animation idle, damage, dead;
  sf::Texture spritesheet;
};

class CageBoss : public Boss
{
public:
  CageBoss(sf::Vector2f pos)
  {
    sprite.setPosition(pos);

    spritesheet.loadFromFile("art/mobs/boss/cageBoss.png");
    idle.setSpriteSheet(spritesheet);

    idle.addFrame(sf::IntRect(7, 3, 221, 249));
    idle.addFrame(sf::IntRect(270, 3, 202, 249));
    idle.addFrame(sf::IntRect(507, 3, 222, 249));
    idle.addFrame(sf::IntRect(769, 3, 210, 249));

    sprite.setAnimation(idle);
  };
  void update(sf::Time deltaTime)
  {
    sprite.update(deltaTime);
  };
private:
  Animation idle, damage, dead;
  sf::Texture spritesheet;
};
