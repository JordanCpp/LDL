#include <Arcanum/Managers/SpriteManager.hpp>

using namespace Arcanum::Managers;
using namespace Arcanum::Graphics;

SpriteManager::SpriteManager(LDL::Graphics::RenderContext* renderContext, Loaders::ArtLoader* artLoader) :
    _RenderContext(renderContext),
    _ArtLoader(artLoader)
{
}

SpriteManager::~SpriteManager()
{
    for (auto i = _Sprites.begin(); i != _Sprites.end(); i++)
        delete i->second;
}

Sprite* SpriteManager::GetSprite(const std::string& path)
{
    auto i = _Sprites.find(path);

    Sprite* result = nullptr;

    if (i == _Sprites.end())
    {
        _ArtLoader->Load(path);

        result = new Sprite;

        for (size_t i = 0; i < _ArtLoader->Frames(); i++)
        {
            _ArtLoader->Frame(i);

            Image* image = new Image(_RenderContext, _ArtLoader->Size(), _ArtLoader->Pixels(), _ArtLoader->Offset(), _ArtLoader->Delta());

            result->Append(image);
        }

        _Sprites.emplace(path, result);
    }
    else
    {
        result = i->second;
    }

    return result;
}