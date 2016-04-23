#include "SplashScreen.hpp"

SplashScreen::SplashScreen()
{
  shouldBeActive = true;
  if(!Logo.loadFromFile("art/misc/splashscreen.png"))
  {
    exit(2);
  }
  if(!KeyTex.loadFromFile("art/misc/pushAny.png"))
  {
    exit(2);
  }
  Sprite.setTexture(Logo, true);
  Sprite.setPosition(sf::Vector2f(0, 0));
  KeySprite.setTexture(KeyTex);
  KeySprite.setPosition(480, 590);
  KeySprite.setOrigin(KeySprite.getLocalBounds().width / 2, KeySprite.getLocalBounds().height / 2);
}

void SplashScreen::update()
{
  if(sizeTimer.getElapsedTime().asSeconds() <= 0.75f)
    KeySprite.setScale(1.1f, 1.1f);
  else if(sizeTimer.getElapsedTime().asSeconds() >= 0.75f)
    KeySprite.setScale(0.9f, 0.9f);
  if(sizeTimer.getElapsedTime().asSeconds() >= 1.5f)
    sizeTimer.restart();

  if(timer.getElapsedTime().asSeconds() <= 2) //Allow cont after 2 sec
    return;

  bool isp = false;
  for (int i = sf::Keyboard::A; i <= sf::Keyboard::Z; ++i )
  {
    if(sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i)))
    {
      isp = true;
      break;
    }
  }
  if(isp == true)
    shouldBeActive = false;
}

void SplashScreen::render(sf::RenderWindow& window)
{
  window.draw(Sprite);
  window.draw(KeySprite);
}

bool SplashScreen::getActive()
{
  return shouldBeActive;
}
