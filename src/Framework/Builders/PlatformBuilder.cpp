#include <memory>
#include "PlatformBuilder.h"

void PlatformBuilder::buildGameObject()
{
  m_currentObject = std::make_unique<GameObject>();
}

void PlatformBuilder::buildTransformComponent(const sf::Vector2f &pos, const sf::Vector2f &dim)
{
  if(m_currentObject)
  {
    m_currentObject->getTransform().setPosition(pos);
    m_currentObject->getTransform().setDimension(dim);
  }
}

void PlatformBuilder::buildPhysicsComponent()
{
  if(m_currentObject)
  {
    m_currentObject->setPhysicsComponent(std::make_unique<KetaPhysics::PhysicsComponent>(
        *m_currentObject, KetaPhysics::PhysicsWorld::get(), m_currentObject->getTransform().getPosition(),
        m_currentObject->getTransform().getDimension()));
  }
}

void PlatformBuilder::buildRenderComponent(sf::Texture &texture)
{
  if(m_currentObject)
  {
    m_currentObject->setRenderComponent(std::make_unique<RenderComponent>(*m_currentObject, texture));
  }
}

std::unique_ptr<GameObject> &&PlatformBuilder::getGameObject()
{
  if(m_currentObject)
  {
    return std::move(m_currentObject);
  }
  else
  {
    throw std::runtime_error("No Object Available");
  }
}
