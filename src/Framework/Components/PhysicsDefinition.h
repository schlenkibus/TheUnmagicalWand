#pragma once

#include <Box2D/Box2D.h>
#include <SFML/System.hpp>

namespace KetaPhysics
{
  enum BodyType
  {
    Static,
    Kinematic,
    Dynamic
  };

  static b2BodyDef createStaticBodyDef(const b2Vec2& pos)
  {
    b2BodyDef ret;
    ret.active = false;
    ret.type = b2BodyType::b2_staticBody;
    ret.position = { pos.x, pos.y };
    return ret;
  }

  static b2BodyDef createDynamicBodyDef(const b2Vec2& pos)
  {
    b2BodyDef ret;
    ret.active = true;
    ret.type = b2BodyType::b2_dynamicBody;
    ret.position = { pos.x, pos.y };
    return ret;
  }

  static b2FixtureDef createBoxFixtureDef(b2Shape* shape)
  {
    b2FixtureDef ret;
    ret.shape = shape;
    ret.density = 1;
    return ret;
  }
}
