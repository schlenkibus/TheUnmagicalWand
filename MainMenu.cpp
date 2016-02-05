#include "MainMenu.hpp"

MainMenu::MainMenu()
{
  if(!texBack.loadFromFile("art/backgrounds/blackWall.png"))
    exit(2);
  if(!texStart.loadFromFile("art/misc/start.png"))
    exit(2);
  if(!texContr.loadFromFile("art/misc/controls.png"))
    exit(2);
  if(!texExit.loadFromFile("art/misc/exit.png"))
    exit(2);
  background.setTexture(texBack);
  startButton.setTexture(texStart);
  controlsButton.setTexture(texContr);
  exitButton.setTexture(texExit);

  background.setPosition(0, 0);
  startButton.setPosition(400, 300);
  controlsButton.setPosition(400, 450);
  exitButton.setPosition(400, 600);
}

void MainMenu::render(sf::RenderWindow &window)
{
    window.draw(background);
    window.draw(startButton);
    window.draw(controlsButton);
    window.draw(exitButton);
}

void MainMenu::update(sf::RenderWindow& window)
{
  //TODO Buttons-Switch + external functions for interaction?!
}
