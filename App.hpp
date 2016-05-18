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
  //Game and Menu Stuff
  sf::RenderWindow * window;
  sf::Event event;
  SplashScreen splashScreen;
  MenuHelp menuHelp;
  MainMenu mainMenu;
  Endscreen end;
  Game * game; //Makes it easy to reset
  enum appState {splash, menu, inGame, endScreen, controls};
  appState state;
  //FPS and Update stuff
  sf::Clock clock;
  sf::Time accumulator;
  sf::Time ups;
  sf::Text fpsText;
  sf::Font font;
  float lastTime, currentTime, fps;
  sf::Clock fpsClock;
public:
  App();
  ~App();
  void mainLoop();
  void update();
};
