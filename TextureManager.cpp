#include "TextureManager.hpp"

sf::Texture TextureManager::getTexture(std::string texName)
{
  for( std::map<std::string, sf::Texture>::const_iterator it = textures.begin();
         it != textures.end();
         ++it)
    {
        if( texName == it->first )
        {
            std::cout << "DEBUG_MESSAGE: using existing tetxure from: " << &textures[texName] << std::endl;
            return it->second;
        }
    }
    sf::Texture tex;
    if(tex.loadFromFile(texName))
    {
        textures[texName] = tex;
        std::cout << "DEBUG_MESSAGE: loading texture into: " << &textures[texName] << std::endl;
        return textures[texName];
    }

    std::cout << "GAME_ERROR: Tetxure was not found. It is filled with an empty texture.\n";
    textures[texName] = tex;
    return textures[texName];
}
