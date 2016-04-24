#include "platform.hpp"

Platform::Platform(sf::Vector2f pos, sf::Texture tex)
{
  sprite.setTexture(tex, true);
  sprite.setPosition(pos);
}

void Platform::draw(sf::RenderWindow &window)
{
  window.draw(sprite);
}
