#include "Transform.h"
#include "GameObject.h"

Transform::Transform(GameObject& parent)
    : m_parent{ parent }
    , m_position{ 0, 0 }
{
}

void Transform::setPosition(const sf::Vector2f& p)
{
  m_position = p;
  m_parent.notifyTransformChanged();
}

const sf::Vector2f& Transform::getPosition() const
{
  return m_position;
}

void Transform::setDimension(const sf::Vector2f& dimension)
{
  m_dimension = dimension;
  m_parent.notifyTransformChanged();
}

const sf::Vector2f& Transform::getDimension() const
{
  return m_dimension;
}
