#include "SFML/Graphics.hpp"

class MainMenu
{
private:
  sf::Sprite background, startButton, controlsButton, exitButton;
  sf::Texture texBack, texStart, texContr, texExit;
public:
  MainMenu();
  void update();
  void render(sf::RenderWindow& window);
};
