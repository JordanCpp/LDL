// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Managers_SpriteManager_hpp
#define Arcanum_Managers_SpriteManager_hpp

#include <map>
#include <string>
#include <Arcanum/Graphics/Sprite.hpp>
#include <Arcanum/Managers/FileManager.hpp>
#include <Arcanum/Loaders/ArtLoader.hpp>
#include <Arcanum/Managers/PathManager.hpp>

namespace Arcanum
{
	class SpriteManager
	{
	public:
		SpriteManager(LDL_RenderContext* renderContext, FileManager* fileManager, ArtLoader* artLoader, PathManager* pathManager);
		~SpriteManager();
		Sprite* GetSprite(const std::string& dir, const std::string& file);
		Sprite* GetScenery(const std::string& fileName);
		Sprite* GetTile(const std::string& fileName);
		Sprite* GetInterface(const std::string& fileName);
	private:
		typedef std::map<std::string, Sprite*> container;
		LDL_RenderContext* _renderContext;
		FileManager*       _fileManager;
		ArtLoader*         _artLoader;
		PathManager*       _pathManager;
		container          _sprites;
	};
}

#endif    
