#pragma once
#include "Components/AnimationComponent.hpp"
#include "Components/PhysicsComponent.hpp"
#include "Components/RenderComponent.h"
#include "Transform.h"
#include <functional>
#include <memory>

class GameObject
{
 public:
  GameObject();

  virtual void update(double delta);
  virtual void draw(sf::RenderWindow& window) const;

  Transform& getTransform();

  template <class tCB> void onTransformChanged(tCB&& cb)
  {
    m_onTransformChangedCallbacks.emplace_back(cb);
  }

  void setRenderComponent(std::unique_ptr<RenderComponent>&& ptr);
  void setPhysicsComponent(std::unique_ptr<KetaPhysics::PhysicsComponent>&& ptr);

 protected:
  Transform m_transform;

  std::unique_ptr<RenderComponent> m_renderer;
  std::unique_ptr<KetaPhysics::PhysicsComponent> m_physiscs;

  void notifyTransformChanged();

  friend class Transform;
  friend class GameObjectBuilder;

  std::vector<std::function<void(const sf::Vector2f&)>> m_onTransformChangedCallbacks;
};