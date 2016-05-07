#include "Player.hpp"

void Player::draw(sf::RenderWindow& window)
{
  playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, 0);
  playerSprite.setPosition(phys.update());
  window.draw(playerSprite);
}
