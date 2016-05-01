#pragma once

#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include "platform.hpp"
#include "TextureManager.hpp"
#include <iostream>
#include "JsonParser.hpp"

typedef std::shared_ptr<Platform> t_Platforms;
typedef std::list<t_Platforms> t_List;

class testLevel
{
public:
  testLevel();
  ~testLevel();
  void draw(sf::RenderWindow &window);
private:
  t_List platforms;
  JsonParser* levelData;
  sf::Sprite background;
  TextureManager texMan;
  sf::Texture backgroundTex, platformTex;
};
