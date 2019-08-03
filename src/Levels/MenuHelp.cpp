#include "MenuHelp.hpp"

MenuHelp::MenuHelp()
{
  shouldBeActive = true;

  backTex.loadFromFile("art/backgrounds/blackWall.png");
  contrTex.loadFromFile("art/misc/controls.png");
  anyTex.loadFromFile("art/misc/pushAny.png");

  background.setTexture(backTex);
  controls.setTexture(contrTex);
  anyKey.setTexture(anyTex);

  background.setPosition(0, 0);
  controls.setPosition(200, 300);
  anyKey.setPosition(350, 500);
}

void MenuHelp::update()
{
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

void MenuHelp::render(sf::RenderWindow &window)
{
  window.draw(background);
  window.draw(controls);
  window.draw(anyKey);
}

bool MenuHelp::getActive()
{
  return shouldBeActive;
}

void MenuHelp::setActive()
{
  shouldBeActive = true;
}
