#include "testLevel.hpp"

#define color sf::Color(49, 124, 49)

testLevel::testLevel()
{
  levelData = new JsonParser("testLevel.json");

  if(levelData->searchForTerm("platform") == true)
  {
    std::string tempString, tempPosString, tempX, tempY;
    int tempTempY;
    for(unsigned int i = 0; i <= levelData->getLines()-1; i++) //does it x times. x -> number of matches
    {
      tempString = levelData->getLineWithMatch(i, "platform");
      if(!tempString.empty())
      {
        tempPosString = tempString.substr(tempString.find("pos(") + 4);
        for(int i = 0; i <= tempPosString.size(); i++)
        {
          if(tempPosString[i] == '/')
          {
            tempX = tempPosString.substr(0, i);
            tempTempY = i + 1;
            std::cout << "tempX: " << tempX << std::endl;
          }
          if(tempPosString[i] == ')')
          {
            tempY = tempPosString.substr(tempTempY, i-tempTempY);
            std::cout << "tempY: " << tempY << std::endl;
          }
        }
      }
    }
  }

  platformTex = texMan.getTexture("art/platforms/platform2x1_2.png");
  testPlatform = new Platform(sf::Vector2f(200, 550), platformTex);
  testPlatform->sprite.setTexture(platformTex);
  testPlatform->sprite.setColor(color);

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
}
