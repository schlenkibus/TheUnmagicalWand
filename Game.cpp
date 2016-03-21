#include "Game.hpp"

#include <iostream>
#include <vector>

Game::Game()
{
  setGameStateToStart();
}

Game::~Game()
{

}

void Game::addLevel(Level& level)
{
  Game::levels.emplace_back(level);
}

void Game::update(sf::RenderWindow &window)
{
  switch(currentGameState)
  {
    case start:
      std::cout << "GAME LÄUFT!" << std::endl;
    break;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    currentGameState = returnToMenu;
}

void Game::render(sf::RenderWindow& window)
{
  //TODO add render stuff!
}

Game::GameState Game::getGameState()
{
  return currentGameState;
}

void Game::setGameStateToStart()
{
  currentGameState = start;
}
