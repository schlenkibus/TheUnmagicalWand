#include "PhysicsWorld.h"
#include "Components/PhysicsComponent.hpp"
#include "Components/PhysicsDefinition.h"

namespace KetaPhysics
{
  PhysicsWorld &PhysicsWorld::get()
  {
    static PhysicsWorld s_world;
    return s_world;
  }

  PhysicsWorld::PhysicsWorld()
      : m_world{ b2Vec2(0, 9.81f) }
  {
  }

  b2Body *PhysicsWorld::createStaticBoxBody(const sf::Vector2f &position, const sf::Vector2f &absoluteDimensions)
  {
    BodyData data;
    data.m_bodyDef = KetaPhysics::createStaticBodyDef({ position.x, position.y });
    data.m_body = m_world.CreateBody(&data.m_bodyDef);
    data.m_shape = {};
    data.m_shape.SetAsBox(absoluteDimensions.x / 2, absoluteDimensions.y / 2,
                          { absoluteDimensions.x / 2, absoluteDimensions.y / 2 }, 0);
    data.m_fixtureDef = KetaPhysics::createBoxFixtureDef(&data.m_shape);
    data.m_fixture = data.m_body->CreateFixture(&data.m_fixtureDef);
    m_bodyData.emplace_back(std::move(data));
    return m_bodyData.back().m_body;
  }

  void PhysicsWorld::removeBodyFromWorld(b2Body *body)
  {
    for(auto it = m_bodyData.begin(); it != m_bodyData.end(); ++it)
    {
      const auto &data = *it;
      if(data.m_body == body)
      {
        data.m_body->DestroyFixture(data.m_fixture);
        m_world.DestroyBody(data.m_body);
        m_bodyData.erase(it);
        return;
      }
    }
  }
}
