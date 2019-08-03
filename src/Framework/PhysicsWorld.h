#pragma once

#include "Components/PhysicsComponent.hpp"
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

namespace KetaPhysics
{
  class PhysicsWorld
  {
   public:
    static PhysicsWorld& get();

    b2Body* createStaticBoxBody(const sf::Vector2f& position, const sf::Vector2f& absoluteDimensions);

    void removeBodyFromWorld(b2Body* body);

   protected:
    struct BodyData
    {
      b2BodyDef m_bodyDef;
      b2FixtureDef m_fixtureDef;
      b2PolygonShape m_shape;
      b2Fixture* m_fixture;
      b2Body* m_body;
    };

    PhysicsWorld();

    b2World m_world;
    std::vector<BodyData> m_bodyData;
  };
}
