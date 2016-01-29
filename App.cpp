#include "App.hpp"

App::App()
{
  window = new sf::RenderWindow(sf::VideoMode(1000, 800), "The Unmagical Wand", sf::Style::Close);
  state = splash;
}

App::~App()
{
  delete window;
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
      return;
    break;
    case menu:
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
