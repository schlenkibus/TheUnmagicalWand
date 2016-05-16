#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Endscreen
{
public:
  Endscreen()
  {
    tex.loadFromFile("art/misc/final_screen.png");
    sprite.setPosition(0, 0);
    sprite.setTexture(tex);
    shouldBeActive = true;
  }

  void update()
  {
    if(sizeTimer.getElapsedTime().asSeconds() <= 0.75f)
      pressAny.setScale(1.1f, 1.1f);
    else if(sizeTimer.getElapsedTime().asSeconds() >= 0.75f)
      pressAny.setScale(0.9f, 0.9f);
    if(sizeTimer.getElapsedTime().asSeconds() >= 1.5f)
      timer.restart();

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

  void draw(sf::RenderWindow& window)
  {
    window.draw(sprite);
  }
private:
  bool shouldBeActive;
  sf::Clock sizeTimer, timer;
  sf::Texture tex;
  sf::Sprite sprite, pressAny;
};
