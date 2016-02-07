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
      splashScreen.render(*window);
      splashScreen.update();
      if(splashScreen.getActive() == false)
      {
        state = menu;
      }
      return;
    break;
    case menu:
      mainMenu.render(*window);
      return;
    break;
    case game:
      return;
    break;
    case endScreen:
      return;
    break;
    default:
      return;
    break;
  }
}
