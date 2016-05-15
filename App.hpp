#pragma once
#include <SFML/Graphics.hpp>
#include "SplashScreen.hpp"
#include "JsonParser.hpp"
#include "MainMenu.hpp"
#include "MenuHelp.hpp"
#include "Game.hpp"
#include "Endscreen.hpp"

class App
{
private:
  sf::RenderWindow * window;
  sf::Event event;
  SplashScreen splashScreen;
  MenuHelp menuHelp;
  MainMenu mainMenu;
  Endscreen end;
  Game * game; //Makes it easy to reset
  JsonParser * parser;
  enum appState {splash, menu, inGame, endScreen, controls};
  appState state;
  sf::Clock clock;
  sf::Time accumulator;
  sf::Time ups;
public:
  App();
  ~App();
  void mainLoop();
  void update();
};
