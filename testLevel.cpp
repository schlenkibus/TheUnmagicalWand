#include "testLevel.hpp"

#define color sf::Color(49, 124, 49)

testLevel::testLevel()
{
  //Loading level and texturedata

  levelData = new JsonParser("testLevel.json");
  texMan.getTexture("art/backgrounds/prison.png");
  texMan.getTexture("art/platforms/platform2x1_2.png");

  platformTex = texMan.getTexture("art/platforms/platform2x1_2.png");

  if(levelData->searchForTerm("platform") == true)
  {
    //Temporary variables
    std::string tempString, tempX, tempY;
    std::string::size_type sz;
    int tempTempY;
    float x, y;

    //Iterate through the lines of the levelJson
    for(unsigned int i = 0; i <= levelData->getLines()-1; i++)
    {
      tempString = levelData->getLineWithMatch(i, "platform"); //if line contains "platform" then continue
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
      platforms.emplace_back(new Platform(sf::Vector2f(x, y), platformTex)); //and create a new platform w/ the position - add it to the list (in a shared pointer)
    }
  }

  for(auto u: platforms)
  {
    u->sprite.setTexture(platformTex);
    u->sprite.setColor(color);
  }

  background.setTexture(texMan.getRef("art/backgrounds/prison.png"));
  background.setPosition(0, 0);
}

testLevel::~testLevel()
{
  delete levelData;
}

void testLevel::draw(sf::RenderWindow &window)
{
  window.draw(background);
  for(auto u: platforms)
  {
    u->draw(window);
  }
}
