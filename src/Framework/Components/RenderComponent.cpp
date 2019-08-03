#include "RenderComponent.h"
#include "../GameObject.h"

RenderComponent::RenderComponent(GameObject& parent, sf::Texture& texture)
    : m_parent{ parent }
    , m_sprite{}
{
  m_sprite.setTexture(texture);
  m_sprite.setPosition(m_parent.getTransform().getPosition());

  m_parent.onTransformChanged([this](const sf::Vector2f& pos) { m_sprite.setPosition(pos); });
}

void RenderComponent::draw(sf::RenderWindow& window) const
{
  window.draw(m_sprite);
}

void RenderComponent::setTexture(sf::Texture& texture)
{
  m_sprite.setTexture(texture, true);
}

void RenderComponent::setTextureRect(const sf::Rect<int>& rect)
{
  m_sprite.setTextureRect(rect);
}