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
    //Left and right movement w/ normalizing slow speeds to stop.
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
    if(position.y + size.y <= 637.0f)
    {
      if(acc.y <= maxYspeed)
        acc.y = acc.y + 1;
    }
    else
    {
      acc.y = 0;
    }

    //Fix Platform and Ground-Collison
    if(position.y  > 637.0f)
    {
      position.y = 637.0f - size.y;
    }

    //Jump! Needs some fixing it does not feel right! The up movement is too fast but too slow you know what i mean
    if(canJump == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      acc.y = -15.0f;
      jumpTimer.restart();
      canJump = false;
      inJump = true;
    }


    //Collision w/ Ground forces jump to stop
    if(inJump && position.y + size.y <= 637.0f) //TODO Platformcollison
    {
      acc.y = acc.y - 0.4f;
    }
    else if(acc.y < 0.5f && acc.y > -0.5f) //normalize the y-acceleration to stop when slow
    {
      acc.y = 0;
      canJump = true;
      inJump = false;
    }


    //Normalize the x-axis acceleration to stop when slow
    if(acc.x > maxXspeed)
    {
      acc.x = maxXspeed;
    }
    if(acc.x < -maxXspeed && acc.x < 0)
    {
      acc.x = -maxXspeed;
    }

    //Set the Position according to acceleration
    position.x = position.x + acc.x;
    position.y = position.y + acc.y;
    return position;
}
