#include "PhysicsComp.hpp"

PhysicsComponent::PhysicsComponent(sf::Vector2f pos, sf::Vector2f s)
{
    size = s;
    position = pos;
}

sf::Vector2f PhysicsComponent::update()
{
    std::cout << "sum " << position.y + size.y << std::endl;
    if(position.y + size.y <= 700.0f)
    {
        position.y + 1;
        return position;
    }
}