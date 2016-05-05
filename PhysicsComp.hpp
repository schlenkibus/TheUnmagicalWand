#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <list>
#include "JsonParser.hpp"

#define gravity 9,8
#define maxYspeed 2
#define maxXspeed 2
#define negAcc 0.05f
#define posAcc 0.33f
#define jumpHeight 12.5f

typedef std::shared_ptr<sf::Vector2f> t_PlatformVec;
typedef std::list<t_PlatformVec> t_VecList;

class PhysicsComponent
{
  public:
    PhysicsComponent(sf::Vector2f pos, sf::Vector2f s);
    ~PhysicsComponent();
    sf::Vector2f update(); //returns new Position to parent
    bool setCurrentLevelAndLoadData(std::string levelJson); //returns false if loading went wrong, deletes the old level before loading new one
    bool checkOnPlatform(); //This is a temp function which does more than the name suggests: it reads the physic-obj and checks if the player is about to land on them -> bad performance
  private:
    JsonParser* levelLoader;
    t_VecList platforms;
    sf::Vector2f position, size;
    sf::Vector2f acc;
    float jumpY;
    bool canJump, inAir, jumpFrame;
    sf::Clock jumpTimer, jumpTreshold;
};
