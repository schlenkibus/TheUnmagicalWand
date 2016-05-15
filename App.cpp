#include "App.hpp"

App::App()
{
  parser = new JsonParser("test.json");
  window = new sf::RenderWindow(sf::VideoMode(1000, 750), "The Unmagical Wand", sf::Style::Close);
  state = splash;
  ups  = sf::seconds(1.f / 60.f);
  accumulator = sf::Time::Zero;
  game = new Game();
}

App::~App()
{
  delete window;
  delete parser;
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
    update(); // renders too
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
        state = inGame;
      mainMenu.render(*window);
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
      accumulator += clock.restart();
      return;
    break;
    case endScreen:
        end.update();
        end.draw(*window);
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
    default:
      return;
    break;
  }
}
