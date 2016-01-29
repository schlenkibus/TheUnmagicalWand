#pragma once
#include <SFML/Graphics.hpp>

class App
{
private:
  sf::RenderWindow * window;
  sf::Event event;
  enum appState {splash, menu, game, endScreen};
public:
  App();
  ~App();
  void mainLoop();
  void update();
};
