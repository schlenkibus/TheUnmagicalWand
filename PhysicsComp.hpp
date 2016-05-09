#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <list>
#include "JsonParser.hpp"

#define _gravity 1.5f
#define _maxYspeed 4.3f
#define _maxXspeed 2.1f
#define _negAcc 0.5f
#define _posAcc 1.25f
#define _jumpHeight 22

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
    void jumpLogic();
    void moveLogic();
  private:
    JsonParser* levelLoader;
    JsonParser* settingsLoader;
    t_VecList platforms;
    sf::Vector2f position, size;
    sf::Vector2f acc;
    float jumpY;
    bool canJump, inAir, jumpFrame;
    sf::Clock jumpTimer, jumpTreshold;
    //Settings-related stuff
    float gravity, maxYspeed, maxXspeed, negAcc, posAcc, jumpHeight;
};
