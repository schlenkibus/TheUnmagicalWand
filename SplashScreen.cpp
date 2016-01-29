#include "SplashScreen.hpp"

SplashScreen::SplashScreen()
{
  if(!Logo.loadFromFile("art/misc/splashscreen.png"))
  {
    exit(2);
  }
  Sprite.setTexture(Logo, true);
  Sprite.setPosition(sf::Vector2f(0, 0));
}

void SplashScreen::render(sf::RenderWindow& window)
{
  window.draw(Sprite);
}
