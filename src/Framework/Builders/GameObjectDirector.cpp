#include "GameObjectDirector.h"
#include "PlatformBuilder.h"

GameObjectDirector &GameObjectDirector::get()
{
  static GameObjectDirector s_direx;
  return s_direx;
}

std::unique_ptr<GameObjectBuilder> GameObjectDirector::getBuilder(const LevelEnums::ObjectType &type)
{
  switch(type)
  {
    case LevelEnums::ObjectType::Platform:
      return std::move(std::make_unique<PlatformBuilder>());
    case LevelEnums::ObjectType::FirePick:
      break;
    case LevelEnums::ObjectType::StonePick:
      break;
    case LevelEnums::ObjectType::WebPick:
      break;
  }
  return nullptr;
}
