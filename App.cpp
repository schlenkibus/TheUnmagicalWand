#include "App.hpp"

App::App()
{
  parser = new JsonParser("test.json");
  window = new sf::RenderWindow(sf::VideoMode(1000, 750), "The Unmagical Wand", sf::Style::Close);
  state = splash;
  canUpdate = true;
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
    update(); // renders too
    window->display();
  }
}

void App::update()
{
  //Limits the game-update calls to 30 per second
  if(canUpdate == false && updateClock.getElapsedTime().asSeconds() >= 0.03333333333f)
  {
    std::cout << "Update - Tick: " << updateClock.getElapsedTime().asSeconds() << std::endl;
    canUpdate = true;
    updateClock.restart();
  }
  else
    canUpdate = false;

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

      if(canUpdate)
        game.update(*window);

      if(game.getGameState() == Game::returnToMenu)
      {
        state = menu;
        game.setGameStateToStart();
      }
      game.render(*window);
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
