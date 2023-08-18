#ifndef Arcanum_Managers_SpriteManager_hpp
#define Arcanum_Managers_SpriteManager_hpp

#include <Arcanum/Graphics/Sprite.hpp>
#include <Arcanum/Managers/FileManager.hpp>
#include <Arcanum/Loaders/ArtLoader.hpp>
#include <Arcanum/Managers/PathManager.hpp>

#include <unordered_map>
#include <string>

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
			LDL::Graphics::RenderContext* _RenderContext;
			Managers::FileManager* _FileManager;
			Loaders::ArtLoader* _ArtLoader;
			Managers::PathManager* _PathManager;
			std::unordered_map<std::string, Graphics::Sprite*> _Sprites;
		};
	}
}

#endif    