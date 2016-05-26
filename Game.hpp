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

  enum GameState {start, inLevel, levelLoad, dead, levelFinished, gameFinished, returnToMenu};

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
  void checkLevelChange();
private:
  sf::Clock cheatClock;
  t_LevelList levels;
  Level * current;
  Player player;
  Hud hud;
  short levelsFinished;
};
