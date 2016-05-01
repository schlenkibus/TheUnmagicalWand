#include "testLevel.hpp"

#define color sf::Color(49, 124, 49)

testLevel::testLevel()
{

  platformTex = texMan.getTexture("art/platforms/platform2x1_2.png");

  levelData = new JsonParser("testLevel.json");

  if(levelData->searchForTerm("platform") == true)
  {
    //Temporary variables
    std::string tempString, tempX, tempY;
    std::string::size_type sz;
    int tempTempY;
    float x, y;

    for(unsigned int i = 0; i <= levelData->getLines()-1; i++)
    {
      tempString = levelData->getLineWithMatch(i, "platform");
      if(!tempString.empty())
      {
        tempString = tempString.substr(tempString.find("pos(") + 4);
        for(int i = 0; i <= tempString.size(); i++)
        {
          if(tempString[i] == '/')
          {
            tempX = tempString.substr(0, i);
            tempTempY = i + 1;
          }
          if(tempString[i] == ')')
          {
            tempY = tempString.substr(tempTempY, i-tempTempY);
          }
        }
      }
      x = std::stof(tempX, &sz);
      y = std::stof(tempY, &sz);
      platforms.emplace_back(new Platform(sf::Vector2f(x, y), platformTex));
    }
  }

  testPlatform = new Platform(sf::Vector2f(200, 550), platformTex);
  testPlatform->sprite.setTexture(platformTex);
  testPlatform->sprite.setColor(color);

  for(auto u: platforms)
  {
    u->sprite.setTexture(platformTex);
    u->sprite.setColor(color);
  }

  backgroundTex = texMan.getTexture("art/backgrounds/prison.png");
  background.setTexture(backgroundTex);
  background.setPosition(0, 0);
}

testLevel::~testLevel()
{
  delete testPlatform;
}

void testLevel::draw(sf::RenderWindow &window)
{
  window.draw(background);
  testPlatform->draw(window);
  for(auto u: platforms)
  {
    u->draw(window);
  }
}
