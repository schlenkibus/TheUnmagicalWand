#include "PhysicsComp.hpp"

#define _gravity 9.81f
#define _maxYspeed 10
#define _maxXspeed 7.5f
#define _negAcc 0.5f
#define _posAcc 1.25f
#define _jumpHeight 60

PhysicsComponent::PhysicsComponent(sf::Vector2f pos, sf::Vector2f s)
{
    size = s;
    position = pos;
    acc.x = 0;
    acc.y = 0;
    inAir = true;

    faceRight = true;

    setCurrentLevelAndLoadData("level1.json");
}

PhysicsComponent::~PhysicsComponent()
{
  delete levelLoader;
}

sf::Vector2f PhysicsComponent::update()
{
  jumpLogic();
  moveLogic();
  position.x = position.x + acc.x;
  position.y = position.y + acc.y;

  if(acc.x > 0)
    faceRight = true;
  else if(acc.x < 0)
    faceRight = false;

  return position;
}

void PhysicsComponent::moveLogic()
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)
  || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    if(acc.x >= -_maxXspeed)
    {
      acc.x -= _posAcc;
    }
    else if (acc.x <= -_maxXspeed)
    {
      acc.x = -_maxXspeed;
    }
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)
  || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    if(acc.x <= _maxXspeed)
    {
      acc.x += _posAcc;
    }
    else if (acc.x >= _maxXspeed)
    {
      acc.x = _maxXspeed;
    }
  }
  else
  {
    if(acc.x >= -0.7f && acc.x <= 0.7f)
    {
      acc.x = 0;
    }
    else
    {
      if(acc.x < 0)
        acc.x += _negAcc;
      else if(acc.x > 0)
        acc.x -= _negAcc;
    }
  }
}

void PhysicsComponent::jumpLogic()
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && inAir == false)
  {
    acc.y -= _jumpHeight;
    inAir = true;
  }
  if(checkOnPlatform() == true)
  {
    inAir = false;
    acc.y = 0;
  }
  else
  {
    inAir = true;
  }

  if(inAir)
  {
    if(acc.y < _maxYspeed)
    {
      acc.y += _gravity;
    }
    else if(acc.y > _maxYspeed)
    {
      acc.y = _maxYspeed;
    }

    if(position.y + acc.y >= 666 - size.y)
    {
      acc.y = 0;
      position.y = 666 - size.y;
      inAir = false;
    }
  }
}

bool PhysicsComponent::setCurrentLevelAndLoadData(std::string levelJson)
{
  levelLoader = new JsonParser(levelJson);

  platforms.clear();

  if(levelLoader->searchForTerm("platform") == true)
  {
    std::string tempString, tempX, tempY;
    std::string::size_type sz;
    int tempTempY;
    float x, y;

    for(unsigned int i = 0; i <= levelLoader->getLines()-1; i++)
    {
      tempString = levelLoader->getLineWithMatch(i, "platform"); //if line contains "platform" then continue
      if(!tempString.empty())
      {
        tempString = tempString.substr(tempString.find("pos(") + 4); //get number after "pos("
        for(int i = 0; i <= tempString.size(); i++)
        {
          if(tempString[i] == '/')
          {
            tempX = tempString.substr(0, i);
            tempTempY = i + 1;
          }
          if(tempString[i] == ')') //Get the y-value
          {
            tempY = tempString.substr(tempTempY, i-tempTempY);
          }
        }
      }
      x = std::stof(tempX, &sz);
      y = std::stof(tempY, &sz);
      platforms.emplace_back(new sf::Vector2f(x, y));
    }
  }
}

bool PhysicsComponent::checkOnPlatform() //Expects 173 width of platform
{
  for(auto u: platforms)
  {
    if(position.x <= u->x + 173 && position.x >= u->x)
    {
      if(position.y + size.y <= u->y && position.y + acc.y + size.y >= u->y)
      {
        position.y = u->y - size.y;
        acc.y = 0;
        return true;
      }
    }
  }
  return false;
}

bool PhysicsComponent::facesRight()
{
  return faceRight;
}
