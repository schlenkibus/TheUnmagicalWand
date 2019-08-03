#pragma once
#include "../Framework/GameObject.h"
#include "../LevelParsing/LevelParser.h"
#include "../LevelParsing/json.h"
#include "../tools/TextureManager.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Level
{
public:
  explicit Level(nlohmann::json& json);
  void update(double delta);
  void draw(sf::RenderWindow& window) const;
private:
  std::vector<std::unique_ptr<GameObject>> m_objects;

  LevelEnums::Theme m_theme;
};
