#include "App.hpp"
#include <stdio.h>

App::App()
{
  auto videoModes = sf::VideoMode::getFullscreenModes();
  for(auto& v : videoModes)
  {
    std::cout << v.width << "x" << v.height << " BitsPerPixel: " << v.bitsPerPixel << std::endl;
  }

  auto desktopMode = sf::VideoMode::getDesktopMode();

  m_window = std::make_unique<sf::RenderWindow>(desktopMode, "The Unmagical Wand", sf::Style::Close);
  m_game = std::make_unique<Game>();

  sf::Event event{};
  sf::Clock frameTime;
  while(m_window->isOpen())
  {
    while(m_window->pollEvent(event))
    {
      handleEvent(event);
    }
    m_game->update(frameTime.getElapsedTime().asSeconds());
    m_window->clear(sf::Color::White);
    m_game->draw(*m_window);
    m_window->display();
    frameTime.restart();
  }
}
void App::handleEvent(const sf::Event& event) const
{
  switch(event.type)
  {
    case sf::Event::Closed:
      m_window->close();
      break;
    case sf::Event::Resized:
      break;
    case sf::Event::LostFocus:
      break;
    case sf::Event::GainedFocus:
      break;
    case sf::Event::TextEntered:
      break;
    case sf::Event::KeyPressed:
      break;
    case sf::Event::KeyReleased:
      break;
    case sf::Event::MouseWheelMoved:
      break;
    case sf::Event::MouseWheelScrolled:
      m_window->close();
      break;
    case sf::Event::MouseButtonPressed:
      break;
    case sf::Event::MouseButtonReleased:
      break;
    case sf::Event::MouseMoved:
      break;
    case sf::Event::MouseEntered:
      break;
    case sf::Event::MouseLeft:
      break;
    case sf::Event::JoystickButtonPressed:
      break;
    case sf::Event::JoystickButtonReleased:
      break;
    case sf::Event::JoystickMoved:
      break;
    case sf::Event::JoystickConnected:
      break;
    case sf::Event::JoystickDisconnected:
      break;
    case sf::Event::TouchBegan:
      break;
    case sf::Event::TouchMoved:
      break;
    case sf::Event::TouchEnded:
      break;
    case sf::Event::SensorChanged:
      break;
    case sf::Event::Count:
      break;
  }
}
