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
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    currentGameState = returnToMenu;

  player.update();
}

void Game::render(sf::RenderWindow& window)
{
  lvl.draw(window);
  player.draw(window);
  hud.draw(window);
}

Game::GameState Game::getGameState()
{
  return currentGameState;
}

void Game::setGameStateToStart()
{
  currentGameState = start;
}
