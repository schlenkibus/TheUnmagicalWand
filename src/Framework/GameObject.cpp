#include "GameObject.h"

GameObject::GameObject()
    : m_transform{ *this }
{
}

void GameObject::update(double delta)
{
  if(m_physiscs)
    m_physiscs->update(delta);
}

void GameObject::draw(sf::RenderWindow &window) const
{
  if(m_renderer)
    m_renderer->draw(window);
}

void GameObject::notifyTransformChanged()
{
  for(auto &cb : m_onTransformChangedCallbacks)
  {
    cb(m_transform.getPosition());
  }
}

Transform &GameObject::getTransform()
{
  return m_transform;
}

void GameObject::setRenderComponent(std::unique_ptr<RenderComponent> &&ptr)
{
  m_renderer = std::move(ptr);
}

void GameObject::setPhysicsComponent(std::unique_ptr<KetaPhysics::PhysicsComponent> &&ptr)
{
  m_physiscs = std::move(ptr);
}
