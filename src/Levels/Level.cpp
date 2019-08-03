#include "Level.hpp"
#include "../Framework/Builders/GameObjectDirector.h"
#include "../LevelParsing/LevelParser.h"

Level::Level(nlohmann::json &json) {
  m_theme = LevelParser::parseTheme(json);
  for(auto& object: *json.find("Objects")) {

    std::cout << object;

    auto type = LevelParser::getType(object);
    auto position = LevelParser::getPosition(object);
    auto size = LevelParser::getDimension(object);
    auto texture = LevelParser::getTexturePath(object);

    auto builder = GameObjectDirector::get().getBuilder(type);
    if(builder) {
      builder->buildGameObject();
      builder->buildTransformComponent(position, size);
      builder->buildRenderComponent(TextureManager::get().getTexture(texture));
      builder->buildPhysicsComponent();
      m_objects.emplace_back(builder->getGameObject());
    }
  }
}

void Level::update(double delta) {
  for(auto& object: m_objects) {
    object->update(delta);
  }
}

void Level::draw(sf::RenderWindow &window) const {
  for(auto& object: m_objects) {
    object->draw(window);
  }
}
