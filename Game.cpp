#include "Game.hpp"

#include <iostream>

Game::Game()
{
  setGameStateToStart();
  levels.emplace_back(new Level("library.json"));
  levels.emplace_back(new Level("kitchen.json"));
  levels.emplace_back(new Level("cellar.json"));
  for(auto u: levels)
  {
    u->setActive(true);
    player.setNewLevel(u->getLevelName());
    return;
  }

}

Game::~Game()
{
}

void Game::update(sf::RenderWindow &window, sf::Time delta)
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    currentGameState = returnToMenu;

  player.update(delta);
  for(auto u: levels)
  {
    if(u->getActive())
      u->update(delta);
  }
  checkLevelChange();
}

void Game::render(sf::RenderWindow& window)
{
  for(auto u: levels)
  {
    if(u->getActive())
      u->draw(window);
  }
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
