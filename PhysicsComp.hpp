#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>

#define gravity 9,8
#define maxYspeed 2
#define maxXspeed 2
#define negAcc 0.05f
#define posAcc 0.33f

class PhysicsComponent
{
  public:
    PhysicsComponent(sf::Vector2f pos, sf::Vector2f s); //Has to obtain leveldata
    sf::Vector2f update(); //returns new Position to parent
    bool checkOnPlatform(int levelNumber); //This is a temp function which does more than the name suggests: it reads the physic-obj and checks if the player is about to land on them -> bad performance
  private:
    sf::Vector2f position, size;
    sf::Vector2f acc;
    bool canJump, inJump;
    sf::Clock jumpTimer, jumpTreshold;
};
