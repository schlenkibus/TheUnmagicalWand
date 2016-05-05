#include "PhysicsComp.hpp"

PhysicsComponent::PhysicsComponent(sf::Vector2f pos, sf::Vector2f s)
{
    size = s;
    position = pos;
    acc.x = 0;
    acc.y = 0;
    canJump = false;
    inAir = true;
    jumpFrame = false; // a bool to determine if the inJump can be changed this frame

    setCurrentLevelAndLoadData("testLevel.json");
}

PhysicsComponent::~PhysicsComponent()
{
  delete levelLoader;
}

sf::Vector2f PhysicsComponent::update()
{
  //Real Input
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump == true)
  {
    std::cout << "Jump!" << std::endl;
    inAir = true;
    canJump = false;
    jumpFrame = true;
    jumpY = position.y;
    acc.y = acc.y - 10;
  }

  if(jumpFrame == true)
  {
    acc.y = acc.y - 0.1f;
    if(position.y <= jumpY - 44.4f)
    {
      jumpFrame = false;
    }
  }

  //Gravity and Platforms
  if(jumpFrame == false)
  {
    if(position.y + size.y >= 637.0f) //Gravity-Collison-Fix
    {
      position.y = 637.0f - size.y;
      acc.y = 0;
      inAir = false;
    }
    if(inAir)
    {
      acc.y = gravity;
    }
    else if(!inAir)
    {
      canJump = true;
    }
  }

  std::cout <<" canJump: " << canJump << " inAir: " << inAir << std::endl;
  position.x = position.x + acc.x;
  position.y = position.y + acc.y;
  return position;
}

bool PhysicsComponent::setCurrentLevelAndLoadData(std::string levelJson)
{
  levelLoader = new JsonParser(levelJson);

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
      //convert the string to float
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
      if(position.y + acc.y <= u->y + 2 && position.y + acc.y >= u->y - 2)
      {
        return true;
      }
      return false;
    }
  }
  return false;
}
