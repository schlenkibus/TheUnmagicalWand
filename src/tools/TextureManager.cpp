#include "TextureManager.hpp"

sf::Texture& TextureManager::getTexture(const std::string& texName)
{
  try
  {
    return m_textures.at(texName);
  }
  catch(const std::out_of_range& err)
  {
    std::cerr << err.what() << " Fetching Texture from disk!" << std::endl;
    m_textures[texName] = sf::Texture();
    if(!m_textures[texName].loadFromFile(texName))
      throw std::runtime_error("Failed to fetch file: " + texName);
    return m_textures[texName];
  }
}

TextureManager& TextureManager::get()
{
  static TextureManager s_tex;
  return s_tex;
}