#include "Player.hpp"

Player::Player() : phys(sf::Vector2f(100, 100), sf::Vector2f(33, 100))
{
  inAction = false;
  playerSprite.setPosition(sf::Vector2f(100, 100));
  playerSprite.setOrigin(sf::Vector2f(playerSprite.getSprite().getLocalBounds().width / 2, 0.0f));
  phys.setCurrentLevelAndLoadData("level1.json");


  webTexture.loadFromFile("art/pickups/projectile.png");

  webAnim.setSpriteSheet(webTexture);

  webAnim.addFrame(sf::IntRect(0, 0, 23, 23));
  webAnim.addFrame(sf::IntRect(24, 0, 23, 23));
  webAnim.addFrame(sf::IntRect(48, 0, 23, 23));
  webAnim.addFrame(sf::IntRect(72, 0, 23, 23));

  webBullet.setAnimation(webAnim);

  webAble = false; stoneAble = false; fireAble = false;
}

void Player::draw(sf::RenderWindow& window)
{
  window.draw(playerSprite.getSprite());
}

void Player::update(sf::Time deltaTime)
{
  if(inAction == false)
  {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
      if(currentPower == web)
      {
        shoot();
      }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && fireAble)
    {
      currentPower = fire;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && webAble)
    {
      currentPower = web;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && stoneAble)
    {
      currentPower = stone;
    }
  }
  else
  {
    if(actionTimer.getElapsedTime().asSeconds() >= 1)
    {
      inAction = false;
    }
  }

  playerSprite.setPosition(phys.update());
  if(phys.facesRight())
  {
    playerSprite.facesRight(true);
  }
  else
  {
    playerSprite.facesRight(false);
  }
  playerSprite.update(deltaTime);
}

void Player::shoot()
{
  inAction = true;
  actionTimer.restart();
  std::cout << "Pew!\n";
}

sf::Vector2f Player::getPosition()
{
  return playerSprite.getSprite().getPosition();
}

void Player::setPosition(sf::Vector2f pos)
{
  playerSprite.setPosition(pos);
  phys.setPosition(pos);
}

void Player::setNewLevel(std::string name)
{
  phys.setCurrentLevelAndLoadData(name);
}
