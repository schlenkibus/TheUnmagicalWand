#include "testLevel.hpp"

#define color sf::Color(49, 124, 49)

testLevel::testLevel()
{

  platformTex = texMan.getTexture("art/platforms/platform2x1_2.png");

  levelData = new JsonParser("testLevel.json");

  std::cout << "sizeof(platforms) " << sizeof(platforms) << std::endl;

  if(levelData->searchForTerm("platform") == true)
  {
    std::string tempString, tempPosString, tempX, tempY;
    std::string::size_type sz;
    int tempTempY;
    for(unsigned int i = 0; i <= levelData->getLines()-1; i++)
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
      float x, y;
      x = std::stof(tempX, &sz);
      y = std::stof(tempY, &sz);
      platforms.emplace_back(new Platform(sf::Vector2f(x, y), platformTex));
    }
  }

  std::cout << "sizeof(platforms) " << sizeof(platforms) << std::endl;

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
  for(auto u: platforms)
  {
    u->draw(window);
  }
}
