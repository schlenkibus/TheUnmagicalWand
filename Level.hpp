#pragma once

#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include "platform.hpp"
#include "TextureManager.hpp"
#include <iostream>
#include "JsonParser.hpp"
#include "Pickup.hpp"
#include "Enemy.hpp"
#include "Boss.hpp"

typedef std::shared_ptr<Platform> t_Platforms;
typedef std::list<t_Platforms> t_PlatformList;

typedef std::shared_ptr<Enemy> t_Enemys;
typedef std::list<t_Enemys> t_EnemyList;

class Level
{
public:
  Level(std::string levelName);
  ~Level()
  {
    delete levelBoss;
  }
  void draw(sf::RenderWindow &window);
  void update(sf::Time deltaTime);
  bool canFinish();
  std::string getLevelName()
  {
    return _levelName;
  }
  bool getActive()
  {
    return active;
  }
  void setActive(bool a)
  {
    active = a;
  }
  void setFinishable()
  {
    finishable = true;
  }
private:
  t_PlatformList platforms;
  t_EnemyList enemys;
  JsonParser* levelData;
  sf::Sprite background;
  TextureManager texMan;
  sf::Texture backgroundTex, platformTex;
  std::string getTexturedata();
  void loadEnemys();
  bool finishable;
  std::string _levelName;
  bool active;
  Boss * levelBoss;
};
