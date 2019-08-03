#pragma once
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>

class GameObject;

class Transform
{
 public:
  explicit Transform(GameObject& parent);

  void setPosition(const sf::Vector2f& p);
  void setDimension(const sf::Vector2f& d);

  const sf::Vector2f& getPosition() const;
  const sf::Vector2f& getDimension() const;

 private:
  sf::Vector2f m_position;
  sf::Vector2f m_dimension;
  GameObject& m_parent;
};
