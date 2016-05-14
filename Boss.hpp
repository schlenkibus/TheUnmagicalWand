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
