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
protected:
  bool faceRight;
  Animation idleL, idleR;
  AnimatedSprite sprite;
  sf::Texture spriteSheetL, spriteSheetR;
};

class Book : public Enemy
{
public:
  Book(sf::Vector2f pos)
  {
    srand((unsigned)time(0));
    x = pos.x;
    y = pos.y;
    sprite.setPosition(pos);

    spriteSheetL.loadFromFile("art/mobs/books/bookL.png");
    spriteSheetR.loadFromFile("art/mobs/books/bookR.png");

    idleL.setSpriteSheet(spriteSheetL);
    idleR.setSpriteSheet(spriteSheetR);

    idleL.addFrame(sf::IntRect(7, 21, 93, 55));
    idleL.addFrame(sf::IntRect(114, 21, 69, 59));
    idleL.addFrame(sf::IntRect(203, 20, 52, 57));

    idleR.addFrame(sf::IntRect(5, 22, 93, 57));
    idleR.addFrame(sf::IntRect(111, 20, 69, 59));
    idleR.addFrame(sf::IntRect(196, 21, 52, 56));

    sprite.setFrameTime(sf::seconds(0.2f));

    sprite.setAnimation(idleR);

    waypoint = generateNewWaypoint();
    linearInterpolation();
  };
  void update(sf::Time deltaTime)
  {
    if(dir.x > 0 && faceRight == false)
    {
      faceRight = true;
      sprite.setAnimation(idleR);
    }
    if(faceRight == true && dir.x < 0)
    {
      faceRight = false;
      sprite.setAnimation(idleL);
    }
    sprite.update(deltaTime);
    pathfinding();
  };
  void pathfinding()
  {
    if( sprite.getPosition().x >= waypoint.x - 20 &&
        sprite.getPosition().x <= waypoint.x + 20 &&
        sprite.getPosition().y >= waypoint.y - 20 &&
        sprite.getPosition().y <= waypoint.y + 20)
    {
      waypoint = generateNewWaypoint();
      linearInterpolation();
    }
    else
    {
      sprite.move(dir * 0.003f);
    }
  };
  sf::Vector2f generateNewWaypoint()
  {
    return sf::Vector2f(RandomFloat(50, 900), RandomFloat(0, 600));
  };
  void linearInterpolation()
  {
    dir = normalize(waypoint, sprite.getPosition());
  }
  float RandomFloat(float min, float max)
  {
	  float r = (float)rand() / (float)RAND_MAX;
	  return min + r * (max - min);
  }
private:
  float x, y, speed, precision;
  sf::Vector2f dir;
  sf::Vector2f waypoint;
  sf::Clock pathClock;
};
