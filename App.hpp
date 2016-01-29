#pragma once
#include <SFML/Graphics.hpp>
#include "SplashScreen.hpp"

class App
{
private:
  sf::RenderWindow * window;
  sf::Event event;
  SplashScreen splashScreen;
  enum appState {splash, menu, game, endScreen};
  appState state;
public:
  App();
  ~App();
  void mainLoop();
  void update();
};
