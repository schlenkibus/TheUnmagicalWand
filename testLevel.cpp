#include "testLevel.hpp"

testLevel::testLevel()
{
  platformTex = texMan.getTexture("art/platforms/platform2x1_2.png");
  testPlatform = new Platform(sf::Vector2f(200, 550), platformTex);

  backgroundTex = texMan.getTexture("art/backgrounds/prison.png");
  background.setTexture(backgroundTex);
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
