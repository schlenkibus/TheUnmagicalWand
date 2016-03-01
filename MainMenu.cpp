#include "MainMenu.hpp"

MainMenu::MainMenu()
  : buttonParser("menu.json")
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

  std::cout << buttonParser.searchForTerm("startButton") << std::endl;

  background.setPosition(0, 0);
  startButton.setPosition(400, 300);
  controlsButton.setPosition(400, 450);
  exitButton.setPosition(400, 600);

  controls = false;
  gameStart = false;
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
  if(isPressed(exitButton, window))
    exit(1);

  if(isPressed(startButton, window))
    gameStart = true;
  else
    gameStart = false;

  if(isPressed(controlsButton, window))
    controls = true;
  else
    controls = false;
}

bool MainMenu::isPressed(sf::Sprite& sprite, sf::RenderWindow &window)
{
  if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    if(sprite.getGlobalBounds().contains((sf::Vector2f) sf::Mouse::getPosition(window)))
    {
      return true;
    }
  }
  return false;
}

bool MainMenu::controlsPressed()
{
  return controls;
}

bool MainMenu::getGameStart()
{
  return gameStart;
}
