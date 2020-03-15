#include "App.hpp"
#include <stdio.h>
#include <TGUI/TGUI.hpp>

using namespace std::string_literals;

auto populateSettingsDialog(tgui::Gui& gui, std::function<void(const sf::VideoMode&, bool)> startGame,
                            std::function<void(void)> cancel)
{
  auto label = tgui::Label::create("Select your preferred Resolution:");

  gui.setTextSize(20);

  auto dropDown = tgui::ComboBox::create();
  int i = 0;
  for(auto& resolutions : sf::VideoMode::getFullscreenModes())
  {
    std::stringstream ss;
    ss << resolutions.width << "x"s << resolutions.height << " "s << resolutions.bitsPerPixel;
    dropDown->addItem(ss.str(), std::to_string(i));

    i++;
  }

  auto fullScreen = tgui::CheckBox::create();
  fullScreen->setChecked(false);

  auto fullScreenLabel = tgui::Label::create("Fullscreen:");

  auto start = tgui::Button::create("Start");
  start->setEnabled(false);

  dropDown->onItemSelect.connect([=]() { start->setEnabled(true); });

  start->onClick.connect([=]() {
    startGame(sf::VideoMode::getFullscreenModes()[dropDown->getSelectedItemIndex()], fullScreen->isChecked());
  });

  auto exit = tgui::Button::create("Exit");
  exit->onClick.connect([=]() { cancel(); });

  label->setSize({"45%", "10%"});
  label->setPosition({"2%", "2%"});

  dropDown->setSize({"45%", "5%"});
  dropDown->setPosition({tgui::bindRight(label), tgui::bindTop(label)});

  fullScreenLabel->setPosition({tgui::bindLeft(label), tgui::bindBottom(dropDown)});
  fullScreen->setPosition({tgui::bindLeft(dropDown), tgui::bindTop(fullScreenLabel)});

  start->setPosition({tgui::bindLeft(label), tgui::bindBottom(fullScreenLabel)});
  exit->setPosition({tgui::bindRight(start), tgui::bindBottom(fullScreenLabel)});

  gui.add(label);
  gui.add(dropDown);
  gui.add(fullScreenLabel);
  gui.add(fullScreen);
  gui.add(start);
  gui.add(exit);
}

App::App()
{
  sf::Event currentEvent {};

  sf::RenderWindow resolutionChooser
      = sf::RenderWindow(sf::VideoMode(800, 600), "The Unmagical Wand - Settings", sf::Style::Close);

  tgui::Gui gui(resolutionChooser);
  populateSettingsDialog(gui, [&](const sf::VideoMode& mode, bool fullscreen) { resolutionChooser.close(); startGame(mode, fullscreen); },
                         [&]() { resolutionChooser.close(); });

  sf::Clock frameTime;
  while(resolutionChooser.isOpen())
  {
    while(resolutionChooser.pollEvent(currentEvent))
    {
      if(currentEvent.type == sf::Event::Closed)
        resolutionChooser.close();

      gui.handleEvent(currentEvent);
    }

    auto delta = frameTime.getElapsedTime();
    resolutionChooser.clear();
    gui.draw();
    resolutionChooser.display();
    frameTime.restart();
  }
}

void App::startGame(const sf::VideoMode& requestedMode, bool fullscreen)
{
  sf::RenderWindow window(requestedMode, "The Unmagical Wand", fullscreen ? sf::Style::Fullscreen : sf::Style::Default);
  sf::Event event{};
  while(window.isOpen()) {
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.display();
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
