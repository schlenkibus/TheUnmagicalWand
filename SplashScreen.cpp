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
  KeySprite.setPosition(343, 187);
}

void SplashScreen::update()
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
  {
    shouldBeActive = false;
  }
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
