#pragma once

#include "../GameObject.h"
class KetaUIContainer : public GameObject
{
 public:
  void update(double delta) override;
  void draw(sf::RenderWindow &window) const override;
private:
    std::vector<std::unique_ptr<GameObject>> m_children;
};
