#include "SFML/Graphics.hpp"

#pragma once

class MainMenu
{
private:
  sf::Sprite background, startButton, controlsButton, exitButton;
  sf::Texture texBack, texStart, texContr, texExit;
public:
  MainMenu();
  //void update(sf::RenderWindow& window);
  void render(sf::RenderWindow& window);
};
