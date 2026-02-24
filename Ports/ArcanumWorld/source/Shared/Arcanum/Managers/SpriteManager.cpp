#include <Arcanum/Managers/SpriteManager.hpp>

using namespace LDL;
using namespace Arcanum::Managers;
using namespace Arcanum::Graphics;
using namespace Arcanum::Loaders;

SpriteManager::SpriteManager(RenderContext* renderContext, FileManager* fileManager, ArtLoader* artLoader, PathManager* pathManager) :
    _renderContext(renderContext),
    _fileManager(fileManager),
    _artLoader(artLoader),
    _pathManager(pathManager)
{
}

SpriteManager::~SpriteManager()
{
    for (container::iterator i = _sprites.begin(); i != _sprites.end(); i++)
    {
        delete i->second;
    }
}

Sprite* SpriteManager::GetSprite(const std::string& dir, const std::string& file)
{
    const char* path = _pathManager->NewShortPath(dir, file).c_str();

    container::iterator i = _sprites.find(path);

    Sprite* result = nullptr;

    if (i == _sprites.end())
    {
        _artLoader->Load(_fileManager->GetFile(path));

        result = new Sprite;

        for (size_t i = 0; i < _artLoader->Frames(); i++)
        {
            _artLoader->Frame(i);

            Image* image = new Image(_renderContext, _artLoader->Size(), _artLoader->Pixels(), _artLoader->Offset(), _artLoader->Delta());

            result->Append(image);
        }

        _sprites.emplace(path, result);
    }
    else
    {
        result = i->second;
    }

    return result;
}

Sprite* SpriteManager::GetScenery(const std::string& fileName)
{
    return GetSprite("art/scenery/", fileName);
}

Sprite* SpriteManager::GetTile(const std::string& fileName)
{
    return GetSprite("art/tile/", fileName);
}

Sprite* SpriteManager::GetInterface(const std::string& fileName)
{
    return GetSprite("art/interface/", fileName);
}