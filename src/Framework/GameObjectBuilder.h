#pragma once

#include "GameObject.h"
#include <memory>

class GameObjectBuilder
{
 public:
  virtual void buildGameObject() = 0;
  virtual void buildTransformComponent(const sf::Vector2f& pos, const sf::Vector2f& dim) = 0;
  virtual void buildPhysicsComponent() = 0;
  virtual void buildRenderComponent(sf::Texture& texture) = 0;
  virtual std::unique_ptr<GameObject>&& getGameObject() = 0;
};
