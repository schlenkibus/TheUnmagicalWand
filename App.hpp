#pragma once
#include <SFML/Graphics.hpp>
#include "SplashScreen.hpp"
#include "JsonParser.hpp"
#include "MainMenu.hpp"
#include "MenuHelp.hpp"

class App
{
private:
  sf::RenderWindow * window;
  sf::Event event;
  SplashScreen splashScreen;
  MenuHelp menuHelp;
  MainMenu mainMenu;
  JsonParser * parser;
  enum appState {splash, menu, game, endScreen, controls};
  appState state;
public:
  App();
  ~App();
  void mainLoop();
  void update();
};
