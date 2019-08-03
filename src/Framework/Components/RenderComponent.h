#pragma once
#include <SFML/Graphics.hpp>

class GameObject;

class RenderComponent
{
 public:
  RenderComponent(GameObject& parent, sf::Texture& texture);

  void setTexture(sf::Texture& texture);
  void setTextureRect(const sf::Rect<int>& rect);
  void draw(sf::RenderWindow& window) const;

 protected:
  sf::Sprite m_sprite;
  GameObject& m_parent;
  friend class GameObject;
};
