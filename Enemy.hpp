#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "AnimatedSprite.h"
#include <iostream>
#include <math.h>
#include <random>

class Enemy
{
public:
  Enemy()
  {
    faceRight = true;
    damage = 10;
    active = true;
  };
  void draw(sf::RenderWindow& window)
  {
    window.draw(sprite);
  };
  virtual void update(sf::Time deltaTime){ };
  bool doesFaceRight()
  {
    return faceRight;
  }
  sf::Vector2f normalize(sf::Vector2f p1, sf::Vector2f p2)
  {
    sf::Vector2f temp;
    temp.x = p1.x - p2.x;
    temp.y = p1.y - p2.y;
    return temp;
  };
  sf::FloatRect getRect()
  {
    return sprite.getGlobalBounds();
  }
  int getDamage()
  {
    return damage;
  }
  bool getActive()
  {
    return active;
  }
protected:
  bool faceRight, active;
  int damage;
  Animation idleL, idleR;
  AnimatedSprite sprite;
  sf::Texture spriteSheetL, spriteSheetR;
};

class Book : public Enemy
{
public:
  Book(sf::Vector2f pos);
  void update(sf::Time deltaTime);
  void pathfinding();
  sf::Vector2f generateNewWaypoint();
  void linearInterpolation();
  float RandomFloat(float min, float max);
private:
  float x, y, speed, precision;
  sf::Vector2f dir;
  sf::Vector2f waypoint;
  sf::Clock pathClock;
};

class Pot: public Enemy
{
public:
  Pot(sf::Vector2f pos);
  void update(sf::Time deltaTime);
  void pathfinding();
  sf::Vector2f generateNewWayPoint();
  void linearInterpolation();
  float RandomFloat(float min, float max);
private:
  float x, y, speed, precision;
  sf::Vector2f dir, waypoint;
  sf::Clock pathClock;
};

class Rat: public Enemy
{
public:
  Rat(sf::Vector2f pos);
  void update(sf::Time deltaTime);
  void pathfinding();
  sf::Vector2f generateNewWayPoint();
  void linearInterpolation();
  float RandomFloat(float min, float max);
private:
  float x, y, speed, precision;
  sf::Vector2f dir, waypoint;
  sf::Clock pathClock;
};
