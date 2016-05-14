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
          player.setPosition(sf::Vector2f(75, 500));
          u->setActive(false);
        }
        else
        {
          return;
        }
      }
      for(auto u: levels)
      {
        if(u->canFinish() == false && u->getActive() == false)
        {
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
  t_LevelList levels;
  Player player;
  Hud hud;
};
