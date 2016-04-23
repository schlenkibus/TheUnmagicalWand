#include "PhysicsComp.hpp"

PhysicsComponent::PhysicsComponent(sf::Vector2f pos, sf::Vector2f s)
{
    size = s;
    position = pos;
    xAcc = 0;
    yAcc = 0;
    acc.x = 0;
    acc.y = 0;
}

sf::Vector2f PhysicsComponent::update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
      if(acc.x > -maxXspeed)
        acc.x = acc.x - posAcc;
    }
    else if(acc.x < 0)
    {
      acc.x = acc.x + negAcc;
    }
    else if(acc.x > 0 && acc.x < 0.1f)
    {
      acc.x = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
      if(acc.x < maxXspeed)
        acc.x = acc.x + posAcc;
    }
    else if(acc.x > 0)
    {
      acc.x = acc.x - negAcc;
    }
    else if(acc.x < 0 && acc.x > -0.1f)
    {
      acc.x = 0;
    }
    //Gravity
    if(position.y + size.y + acc.y <= 700.0f)
    {
      if(acc.y <= maxYspeed)
        acc.y = acc.y + 1;
    }
    else
    {
      acc.y = 0;
    }
    //enforce speedlimit!
    if(acc.x > maxXspeed)
    {
      acc.x = maxXspeed;
    }
    if(acc.x < -maxXspeed && acc.x < 0)
    {
      acc.x = -maxXspeed;
    }
    std::cout << "Acc: " << acc.x << "/" << acc.y << std::endl;
    position.x = position.x + acc.x;
    position.y = position.y + acc.y;
    return position;
}
