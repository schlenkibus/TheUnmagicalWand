
#include "KetaUIContainer.h"
void KetaUIContainer::update(double delta)
{
  GameObject::update(delta);
}

void KetaUIContainer::draw(sf::RenderWindow& window) const
{
  for(auto& child : m_children)
  {
    child->draw(window);
  }
}
