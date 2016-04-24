#include "testLevel.hpp"

testLevel::testLevel()
{
  testPlatform = new Platform(sf::Vector2f(200, 550),
                              texMan.getTexture("art/platforms/platform2x1_2.png"));
  background.setTexture(texMan.getTexture("art/backgrounds/prison.png"), true);
  background.setPosition(0, 0);
}

testLevel::~testLevel()
{
  delete testPlatform;
}

void testLevel::draw(sf::RenderWindow &window)
{
  window.draw(background);
  testPlatform->draw(window);
}
