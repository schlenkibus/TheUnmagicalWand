#include "App.hpp"

App::App()
{
  parser = new JsonParser("test.json");
  window = new sf::RenderWindow(sf::VideoMode(1000, 750), "The Unmagical Wand", sf::Style::Close);
  state = splash;
}

App::~App()
{
  delete window;
  delete parser;
}

void App::mainLoop()
{
  while(window->isOpen())
  {
    while(window->pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        window->close();
      }
    }
    window->clear();
    update();
    window->display();
  }
}

void App::update()
{
  switch(state)
  {
    case splash:
      splashScreen.update();
      splashScreen.render(*window);
      if(splashScreen.getActive() == false)
        state = menu;
      return;
    break;
    case menu:
      mainMenu.update(*window);
      if(mainMenu.controlsPressed())
        state = controls;
      if(mainMenu.getGameStart())
        state = game;
      mainMenu.render(*window);
      return;
    break;
    case game:
      return;
    break;
    case endScreen:
      return;
    break;
    case controls:
      menuHelp.update();
      if(menuHelp.getActive() == false)
      {
        menuHelp.setActive();
        state = menu;
      }
      menuHelp.render(*window);
    default:
      return;
    break;
  }
}
