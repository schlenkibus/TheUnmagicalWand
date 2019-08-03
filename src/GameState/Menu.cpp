#include "Menu.h"

Menu::Menu()
{
  KetaUI::CreateContainer m_objects.emplace_back(std::make_unique<KetaUI::Label>(KetaUI::getMiddle));
}
