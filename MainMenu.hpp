#include "SFML/Graphics.hpp"
#include "JsonParser.hpp"

#pragma once

class MainMenu
{
private:
  JsonParser buttonParser;
  sf::Sprite background, startButton, controlsButton, exitButton;
  sf::Texture texBack, texStart, texContr, texExit;
public:
  MainMenu();
  void update(sf::RenderWindow& window);
  void render(sf::RenderWindow& window);
};
