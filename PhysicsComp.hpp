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
  private:
    sf::Vector2f position, size;
    sf::Vector2f acc;
    bool canJump, inJump;
    sf::Clock jumpTimer, jumpTreshold;
};
