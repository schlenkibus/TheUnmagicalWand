#include "App.hpp"
#include <stdio.h>

App::App()
{
  window = new sf::RenderWindow(sf::VideoMode(1000, 750), "The Unmagical Wand", sf::Style::Close);
  state = splash;
  ups  = sf::seconds(1.f / 60.f);
  accumulator = sf::Time::Zero;
  game = new Game();
  font.loadFromFile("art/fonts/temp.ttf");
  fpsText.setFont(font);
  fpsText.setPosition(0, 0);
  fpsText.setString("v 0.1");
}

App::~App()
{
  delete window;
  delete game;
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
      window->draw(fpsText);
      if(splashScreen.getActive() == false)
        state = menu;
      return;
    break;
    case menu:
      mainMenu.update(*window);
      if(mainMenu.controlsPressed())
        state = controls;
      if(mainMenu.getGameStart())
        state = inGame;
      mainMenu.render(*window);
      window->draw(fpsText);
      return;
    break;
    case inGame:
      while(accumulator > ups)
      {
        accumulator -= ups;
        game->update(*window, ups);
      }
      if(game->getGameState() == Game::returnToMenu)
      {
        state = menu;
        game->setGameStateToStart();
      }
      else if(game->getGameState() == Game::gameFinished)
        state = endScreen;
      game->render(*window);
      window->draw(fpsText);
      accumulator += clock.restart();
      return;
    break;
    case endScreen:
        end.update();
        end.draw(*window);
        window->draw(fpsText);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
          state = menu;
          delete game;
          game = new Game();
        }
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
      window->draw(fpsText);
    default:
      return;
    break;
  }
}
