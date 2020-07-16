#include "Assets.h"

std::map<std::string, Texture> Assets::textures;

Texture Assets::loadTexture(Renderer& renderer, const string& filename, const string& name)
{
    textures[name] = loadTextureFromFile(renderer, filename.c_str());
    return textures[name];
}

Texture& Assets::getTexture(const string& name) 
{
    return textures[name];
}

void Assets::clear() 
{
    // (Properly) delete all textures
    textures.clear();
}

Texture Assets::loadTextureFromFile(Renderer& renderer, const string& filename)
{
    Texture texture;
    texture.load(renderer, filename);
    return texture;
}