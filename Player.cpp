#include "Player.hpp"

Player::Player() : phys(sf::Vector2f(100, 100), sf::Vector2f(33, 100))
{
  health = 100;
  inAction = false;
  playerSprite.setPosition(sf::Vector2f(100, 100));
  playerSprite.setOrigin(sf::Vector2f(playerSprite.getSprite().getLocalBounds().width / 2, 0.0f));
  phys.setCurrentLevelAndLoadData("level1.json");

  dealsDamage = false;

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
  if(health <= 0)
  {
    destroy();
    return;
  }

  if(damageTimer.getElapsedTime().asSeconds() <= 0.5)
  {
    if(animTimer.getElapsedTime().asSeconds() <= 0.05)
    {
      playerSprite.getSprite().setColor(sf::Color::Red);
    }
    else if(animTimer.getElapsedTime().asSeconds() > 0.05 && animTimer.getElapsedTime().asSeconds() <= 0.1)
    {
      playerSprite.getSprite().setColor(sf::Color::White);
    }
    else
    {
      playerSprite.getSprite().setColor(sf::Color::White);
      animTimer.restart();
    }
  }
  else
  {
    playerSprite.getSprite().setColor(sf::Color::White);
  }

  if(inAction == false)
  {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
      if(currentPower == web)
      {
        shoot();
      }
      else if(currentPower == fire)
      {
        hitFire();
      }
      else if(currentPower == stone)
      {
        hitStone();
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
      dealsDamage = false;
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
  std::cout << health << std::endl;
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

void Player::hitFire()
{
  inAction = true;
  dealsDamage = true;
  actionTimer.restart();
  std::cout << "Flame!!\n";
}

void Player::hitStone()
{
  inAction = true;
  dealsDamage = false;
  actionTimer.restart();
  std::cout << "BAM!\n";
}

void Player::destroy()
{
  std::cout << "Player is offialy dead!\n";
}

void Player::dealDamage(int d)
{
  if(damageTimer.getElapsedTime().asSeconds() > 0.5)
  {
    health-=d;
    damageTimer.restart();
  }
}
