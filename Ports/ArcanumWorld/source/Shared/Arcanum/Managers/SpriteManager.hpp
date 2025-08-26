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
	namespace Managers
	{
		class SpriteManager
		{
		public:
			SpriteManager(LDL::Graphics::RenderContext* renderContext, Managers::FileManager* fileManager, Loaders::ArtLoader* artLoader, Managers::PathManager* pathManager);
			~SpriteManager();
			Graphics::Sprite* GetSprite(const std::string& dir, const std::string& file);
			Graphics::Sprite* GetScenery(const std::string& fileName);
			Graphics::Sprite* GetTile(const std::string& fileName);
			Graphics::Sprite* GetInterface(const std::string& fileName);
		private:
			typedef std::map<std::string, Graphics::Sprite*> container;
			LDL::Graphics::RenderContext* _renderContext;
			Managers::FileManager*        _fileManager;
			Loaders::ArtLoader*           _artLoader;
			Managers::PathManager*        _pathManager;
			container                     _sprites;
		};
	}
}

#endif    