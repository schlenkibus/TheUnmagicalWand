#include "App.hpp"
#include <stdio.h>
#include "gui.h"

App::App()
{
  sf::Event currentEvent {};

  sf::RenderWindow resolutionChooser
      = sf::RenderWindow(sf::VideoMode(500, 300), "The Unmagical Wand - Settings", sf::Style::Default);

  gui::Gui resolutionChooserGui;

  int number = 0;
  sf::Font font;
  font.loadFromFile("art/fonts/temp.ttf");
  auto label = resolutionChooserGui.createElement<gui::Label>(&font, "Hallo");
  auto rot = resolutionChooserGui.createElement<gui::Button>(&font, "Welt", [&](auto) {
    label->setText(std::to_string(++number));
    return true;
  });

  rot->setPosition(200, 0);

  gui::Event guiEvent {};

  while(resolutionChooser.isOpen())
  {
    while(resolutionChooser.pollEvent(currentEvent))
    {
      guiEvent.m_event = currentEvent;
      guiEvent.m_mousePos = [](const sf::Vector2i& i) -> sf::Vector2f {
        return sf::Vector2f(i.x, i.y);
      }(sf::Mouse::getPosition(resolutionChooser));
      switch(currentEvent.type)
      {
        case sf::Event::Closed:
          resolutionChooser.close();
          break;
        default:
          if(resolutionChooserGui.handleEvent(guiEvent))
            break;
      }
    }

    resolutionChooser.clear();
    resolutionChooser.draw(resolutionChooserGui);
    resolutionChooser.display();
  }

  return;

  auto videoModes = sf::VideoMode::getFullscreenModes();
  for(auto& v : videoModes)
  {
    std::cout << v.width << "x" << v.height << " BitsPerPixel: " << v.bitsPerPixel << std::endl;
  }

  auto desktopMode = sf::VideoMode::getDesktopMode();

  m_window = std::make_unique<sf::RenderWindow>(desktopMode, "The Unmagical Wand", sf::Style::Close);
  m_game = std::make_unique<Game>();

  sf::Clock frameTime;
  while(m_window->isOpen())
  {
    while(m_window->pollEvent(currentEvent))
    {
      handleEvent(currentEvent);
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
