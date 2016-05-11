#pragma once
#include <SFML/Graphics.hpp>
#include "SplashScreen.hpp"
#include "JsonParser.hpp"
#include "MainMenu.hpp"
#include "MenuHelp.hpp"
#include "Game.hpp"

class App
{
private:
  sf::RenderWindow * window;
  sf::Event event;
  SplashScreen splashScreen;
  MenuHelp menuHelp;
  MainMenu mainMenu;
  Game game;
  JsonParser * parser;
  enum appState {splash, menu, inGame, endScreen, controls};
  appState state;
  sf::Clock updateClock;
  bool canUpdate;
public:
  App();
  ~App();
  void mainLoop();
  void update();
};
