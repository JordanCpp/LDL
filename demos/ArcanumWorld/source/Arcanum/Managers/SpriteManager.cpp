// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Managers/SpriteManager.hpp>

using namespace Arcanum;

SpriteManager::SpriteManager(LDL_RenderContext* renderContext, FileManager* fileManager, ArtLoader* artLoader, PathManager* pathManager) :
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

    Sprite* result = NULL;

    if (i == _sprites.end())
    {
        _artLoader->Load(_fileManager->GetFile(path));

        result = new Sprite;

        for (size_t j = 0; j < _artLoader->Frames(); j++)
        {
            _artLoader->Frame(j);

            Image* image = new Image(_renderContext, _artLoader->Size(), _artLoader->Pixels(), _artLoader->Offset(), _artLoader->Delta());

            result->Append(image);
        }

        _sprites.insert(std::make_pair(path, result));
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
