#include "TextureManager.hpp"

sf::Texture TextureManager::getTexture(std::string texName)
{
  for( std::map<std::string, sf::Texture>::const_iterator it = textures.begin();
         it != textures.end();
         ++it)
    {
        if( texName == it->first )
        {
            return it->second;
        }
    }
    sf::Texture tex;
    if(tex.loadFromFile(texName))
    {
        textures[texName] = tex;
        return textures[texName];
    }
    textures[texName] = tex;
    return textures[texName];
}

TextureManager::~TextureManager()
{
  textures.clear();
}
