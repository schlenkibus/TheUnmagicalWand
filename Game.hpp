#pragma once

#include "SFML/Graphics.hpp"
#include "Level.hpp"
#include <iostream>

class Game
{
public:
  Game();
  ~Game();
  void render(sf::RenderWindow& window);
  void update(sf::RenderWindow& window);
  void addLevel(Level& level);

  enum GameState {start, inLevel, levelLoad, dead,
                  levelFinished, gameFinished, returnToMenu};

  GameState currentGameState;

  void setGameStateToStart();
  GameState getGameState();
private:
  std::vector<Level> levels;
};
