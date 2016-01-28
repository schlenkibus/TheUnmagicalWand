#include "App.hpp"

App::App()
{
  window = new sf::RenderWindow(sf::VideoMode(1000, 800), "The Unmagical Wand", sf::Style::Close);

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
    window->display();
  }
}
