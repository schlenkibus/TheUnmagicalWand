#pragma once

#include "SFML/Graphics.hpp"
#include "Levels/Level.hpp"
#include <iostream>
#include <memory>
#include <list>

class Game
{
 public:
  Game();
  void draw(sf::RenderWindow& window);
  void update(double delta);

 private:
  std::unique_ptr<Level> m_level;
};
