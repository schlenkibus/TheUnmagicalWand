#pragma once

#include "SFML/Graphics.hpp"
#include "Level.hpp"
#include <iostream>
#include <memory>
#include <list>
#include "Player.hpp"
#include "Hud.hpp"

typedef std::shared_ptr<Level> t_Levels;
typedef std::list<t_Levels> t_LevelList;

class Game
{
public:
  Game();
  ~Game();
  void render(sf::RenderWindow& window);
  void update(sf::RenderWindow& window, sf::Time delta);

  enum GameState {start, inLevel, levelLoad, dead,
                  levelFinished, gameFinished, returnToMenu};

  GameState currentGameState;

  void setGameStateToStart();
  GameState getGameState();

  void onFirePickup()
  {
    hud.addFireCount();
  };
  void onStonePickup()
  {
    hud.addStoneCount();
  };
  void onWebPickup()
  {
    hud.addWebCount();
  };
  void checkLevelChange()
  {
    if(player.getPosition().x >= 950)
    {
      for(auto u: levels)
      {
        std::cout << "levels: " << u << std::endl;
        if(u->getActive() == true && u->canFinish() == true)
        {
          levelFinished++;
          player.setPosition(sf::Vector2f(75, 500));
          u->setActive(false);
          std::cout << "old level: " << u << std::endl;
        }
        else if(u->getActive() == true && u->canFinish() == false)
        {
          return;
        }
      }
      for(auto u: levels)
      {
        if(u->canFinish() == false && u->getActive() == false)
        {
          std::cout << "New Level: " <<  u << std::endl;
          player.setNewLevel(u->getLevelName()); //Hope that works
          u->setActive(true);
          return;
        }
      }
    }
    else
    {
      return;
    }
  }
private:
  sf::Clock cheatClock;
  t_LevelList levels;
  Player player;
  Hud hud;
  short levelsFinished; //When 3 then skip to endscreen
};
