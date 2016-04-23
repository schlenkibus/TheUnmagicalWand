#include "Player.hpp"

void Player::draw(sf::RenderWindow& window)
{
    playerSprite.setPosition(phys.update());
    window.draw(playerSprite);
}