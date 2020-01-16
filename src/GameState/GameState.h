#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "../Framework/GameObject.h"

class GameState
{
 public:
  virtual void draw(sf::RenderWindow& window);
  virtual void update(double delta);

 protected:
  std::vector<std::unique_ptr<GameObject>> m_objects;
};