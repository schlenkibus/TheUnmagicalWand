#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

#define gravity 9,8

class PhysicsComponent
{
  public:
    PhysicsComponent(sf::Vector2f pos, sf::Vector2f s); //Has to obtain leveldata
    sf::Vector2f update(); //returns new Position
  private:
    //TODO list w/ leveldata
    sf::Vector2f position, size;
};