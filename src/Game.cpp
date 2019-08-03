#include "Game.hpp"

#include <iostream>

Game::Game()
{
}

void Game::update(double delta)
{
  if(m_level)
  {
    m_level->update(delta);
  }
}

void Game::draw(sf::RenderWindow& window)
{
  if(m_level)
    m_level->draw(window);
}