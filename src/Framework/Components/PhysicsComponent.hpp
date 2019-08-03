#pragma once

#include "../../LevelParsing/JsonParser.hpp"
#include "../PhysicsWorld.h"
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <list>
#include <memory>

class GameObject;

namespace KetaPhysics
{
  class PhysicsWorld;

  class PhysicsComponent
  {
   public:
    PhysicsComponent(GameObject &parent, KetaPhysics::PhysicsWorld &world, const sf::Vector2f &position,
                     const sf::Vector2f &dimension);
    ~PhysicsComponent();
    void update(double delta);

   private:
    GameObject &m_parent;
    PhysicsWorld &m_world;
    b2Body *m_body;
  };
}