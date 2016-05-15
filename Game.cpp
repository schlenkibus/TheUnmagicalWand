#include "Game.hpp"

#include <iostream>

Game::Game()
{
  levelsFinished = 0;
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

bool able = false;

void Game::update(sf::RenderWindow &window, sf::Time delta)
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    currentGameState = returnToMenu;

  if(cheatClock.getElapsedTime().asSeconds() >= 1.5f)
  {
    able = false;
    cheatClock.restart();
  }

  if(levelsFinished == 3)
  {
    currentGameState = gameFinished;
  }

  player.update(delta);
  for(auto u: levels)
  {
    if(u->getActive())
    {
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::L) && able == false)
      {
        able = true;
        u->setFinishable();
      }
      u->update(delta);
    }
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
