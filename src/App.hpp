#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"

class App
{
 private:
  std::unique_ptr<sf::RenderWindow> m_window;
  std::unique_ptr<Game> m_game;

 public:
  App();
  void handleEvent(const sf::Event& event) const;
};
