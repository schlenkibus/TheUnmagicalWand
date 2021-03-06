#pragma once
#include "../GameObjectBuilder.h"

class PlatformBuilder : public GameObjectBuilder
{
 public:
  void buildGameObject() override;
  void buildTransformComponent(const sf::Vector2f &pos, const sf::Vector2f &dim) override;
  void buildPhysicsComponent() override;
  void buildRenderComponent(sf::Texture &texture) override;
  std::unique_ptr<GameObject> &&getGameObject() override;

 protected:
  std::unique_ptr<GameObject> m_currentObject;
};
