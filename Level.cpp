#include "Level.hpp"

Level::Level(std::string levelName)
{

  levelData = new JsonParser("texture"+levelName);

  getTexturedata();

  delete levelData;

  levelData = new JsonParser(levelName);

  texMan.getTexture("art/backgrounds/prison.png");
  texMan.getTexture("art/platforms/platform2x1_2.png");

  platformTex = texMan.getTexture("art/platforms/platform2x1_2.png");

  if(levelData->searchForTerm("platform") == true)
  {
    std::string tempString, tempX, tempY;
    std::string::size_type sz;
    int tempTempY;
    float x, y;

    for(unsigned int i = 0; i <= levelData->getLines()-1; i++)
    {
      tempString = levelData->getLineWithMatch(i, "platform");
      if(tempString == "error")
      {

      }
      else
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
        x = std::stof(tempX, &sz);
        y = std::stof(tempY, &sz);
        platforms.emplace_back(new Platform(sf::Vector2f(x, y), platformTex));
      }
    }
  }
  if(levelData->searchForTerm("book") == true)
  {
    std::string tempString, tempX, tempY;
    std::string::size_type sz;
    int tempTempY;
    float x, y;

    for(unsigned int i = 0; i <= levelData->getLines()-1; i++)
    {
      tempString = levelData->getLineWithMatch(i,"book");
      std::cout << "line: " <<  i << " " << tempString.size() << std::endl;
      if(tempString == "error")
      {

      }
      else
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
        x = std::stof(tempX, &sz);
        y = std::stof(tempY, &sz);
        enemys.emplace_back(new Book(sf::Vector2f(x, y)));
      }
    }
  }
  for(auto u: platforms)
  {
    u->sprite.setTexture(platformTex);
  }

  background.setTexture(texMan.getRef("art/backgrounds/prison.png"));
  background.setPosition(0, 0);

  delete levelData;
}

void Level::draw(sf::RenderWindow &window)
{
  window.draw(background);
  for(auto u: platforms)
  {
    u->draw(window);
  }
  for(auto u: enemys)
  {
    u->draw(window);
  }
}

void Level::update(sf::Time deltaTime)
{
  for(auto u: enemys)
  {
    u->update(deltaTime);
  }
}

std::string Level::getTexturedata()
{

  std::string tempString;
  std::string temp2string;
  tempString = levelData->getLineWithTerm("platformtexture:");
  if(!tempString.empty())
  {
    tempString = tempString.substr(tempString.find("<") + 1);
    for(char i: tempString)
    {
      if(i == '>')
      {
        break;
      }
      if(i != '>')
      {
        temp2string += i;
      }
    }
  }
  return temp2string;
}
