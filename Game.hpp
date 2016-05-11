#pragma once

#include "SFML/Graphics.hpp"
#include "Level.hpp"
#include <iostream>
#include "Player.hpp"
#include "testLevel.hpp"
#include "Hud.hpp"

class Game
{
public:
  Game();
  ~Game();
  void render(sf::RenderWindow& window);
  void update(sf::RenderWindow& window, sf::Time delta);
  void addLevel(Level& level);

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
private:
  std::vector<Level> levels;
  Player player;
  testLevel lvl;
  Hud hud;
};
