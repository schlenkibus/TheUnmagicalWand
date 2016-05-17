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
        if(u->getActive() == true && u->canFinish() == true)
        {
          levelsFinished++;
          player.setPosition(sf::Vector2f(75, 500));
          u->setActive(false);
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
          player.setNewLevel(u->getLevelName());
          u->setActive(true);
          current = u.get();
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
  Level * current;
  Player player;
  Hud hud;
  short levelsFinished; //When 3 then skip to endscreen
};
