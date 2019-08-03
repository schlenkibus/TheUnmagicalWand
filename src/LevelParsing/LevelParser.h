#pragma once

#include "../tools/EnumTools.h"
#include "json.h"
#include <SFML/Window.hpp>

namespace LevelEnums {
  ENUM(Theme, uint8_t, Library, Kitchen, Cellar);
  ENUM(ObjectType, uint8_t, Platform, FirePick, StonePick, WebPick)
  ENUM(MobType, uint8_t, Book, Pot, Rat)
}

namespace LevelParser {


    static LevelEnums::Theme parseTheme(nlohmann::json& levelJson) {
        auto meta = levelJson.find("Meta");
        if(meta != levelJson.end()) {
            auto theme = meta->find("Theme");
            if(theme != levelJson.end()) {
              return LevelEnums::toTheme(*theme);
            }
        }
        return LevelEnums::Theme::Library;
    }

    static LevelEnums::ObjectType getType(nlohmann::json& gameObject) {
      auto type = gameObject.find("Type");
      if(type != gameObject.end()) {
        return LevelEnums::toObjectType(*type);
      }
      return LevelEnums::ObjectType::Platform;
    }

    static sf::Vector2f getPosition(nlohmann::json& gameObject) {
      auto pos = gameObject.find("Position");
      if(pos != gameObject.end()) {
        auto x = pos->find("x");
        auto y = pos->find("y");
        if(x != pos->end() && y != pos->end())
        {
          return {std::stof(std::string(*x)), std::stof(std::string(*y))};
        }
      }
      return {0, 0};
    }

    static sf::Vector2f getDimension(nlohmann::json& gameObject) {
      auto pos = gameObject.find("Dimension");
      if(pos != gameObject.end()) {
        auto w = pos->find("w");
        auto h = pos->find("h");
        if(w != pos->end() && h != pos->end())
        {
          return {std::stof(std::string(*w)), std::stof(std::string(*h))};
        }
      }
      return {0, 0};
    }

    static std::string getTexturePath(nlohmann::json& gameObject) {
      auto str = gameObject.find("Texture");
      if(str != gameObject.end()) {
        return *str;
      }
      return "";
    }
};
