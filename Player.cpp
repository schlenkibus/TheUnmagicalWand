#include "Player.hpp"

void Player::draw(sf::RenderWindow& window)
{
  window.draw(playerSprite.getSprite());
}

void Player::shoot()
{
  inAction = true;
  actionTimer.restart();
  std::cout << "Pew!\n";
}
