#include "PhysicsComponent.hpp"
#include "../GameObject.h"

namespace KetaPhysics
{
  PhysicsComponent::PhysicsComponent(GameObject& parent, PhysicsWorld& world, const sf::Vector2f& position,
                                     const sf::Vector2f& dimension)
      : m_parent{ parent }
      , m_world{ world }
      , m_body{ nullptr }
  {
    m_body = m_world.createStaticBoxBody(position, dimension);
  }

  PhysicsComponent::~PhysicsComponent() = default;

  void PhysicsComponent::update(double delta)
  {
    auto pos = m_body->GetTransform().p;
    if(sf::Vector2f(pos.x, pos.y) != m_parent.getTransform().getPosition())
      m_parent.getTransform().setPosition({ pos.x, pos.y });
  }
}