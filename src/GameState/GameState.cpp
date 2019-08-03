#include "GameState.h"
#include "../Framework/GameObject.h"

void GameState::update(double delta)
{
  for(auto& object : m_objects)
  {
    object->update(delta);
  }
}
void GameState::draw(sf::RenderWindow& window)
{
  for(const auto& object : m_objects)
  {
    object->draw(window);
  }
}
