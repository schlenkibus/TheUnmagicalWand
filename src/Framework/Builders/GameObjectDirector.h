#pragma once

#include "../../LevelParsing/LevelParser.h"
#include "../GameObjectBuilder.h"
class GameObjectDirector
{
 public:
  static GameObjectDirector& get();

  std::unique_ptr<GameObjectBuilder> getBuilder(const LevelEnums::ObjectType& type);

 protected:
  GameObjectDirector() = default;
};
