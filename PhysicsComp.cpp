#include "PhysicsComp.hpp"

PhysicsComponent::PhysicsComponent(sf::Vector2f pos, sf::Vector2f s)
{
    size = s;
    position = pos;
    acc.x = 0;
    acc.y = 0;
    canJump = false;
    inJump = true;
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

    if(canJump == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      acc.y = -7.5f;
      jumpTimer.restart();
      canJump = false;
      inJump = true;
    }

    if(inJump && position.y + size.y + acc.y <= 700.0f) //TODO Platformcollison
    {
      acc.y = acc.y - 0.4f;
    }
    else if(acc.y < 0.5f && acc.y > -0.5f)
    {
      acc.y = 0;
      canJump = true;
      inJump = false;
    }

    if(acc.x > maxXspeed)
    {
      acc.x = maxXspeed;
    }
    if(acc.x < -maxXspeed && acc.x < 0)
    {
      acc.x = -maxXspeed;
    }
    position.x = position.x + acc.x;
    position.y = position.y + acc.y;
    return position;
}
