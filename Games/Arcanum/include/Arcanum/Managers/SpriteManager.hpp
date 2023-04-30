#ifndef Arcanum_Managers_SpriteManager_hpp
#define Arcanum_Managers_SpriteManager_hpp

#include <Arcanum/Graphics/Sprite.hpp>
#include <unordered_map>
#include <string>
#include <Arcanum/Loaders/ArtLoader.hpp>

namespace Arcanum
{
	namespace Managers
	{
		class SpriteManager
		{
		public:
			SpriteManager(LDL::Graphics::RenderContext* renderContext, Loaders::ArtLoader* artLoader);
			~SpriteManager();
			Graphics::Sprite* GetSprite(const std::string& path);
		private:
			LDL::Graphics::RenderContext* _RenderContext;
			Loaders::ArtLoader* _ArtLoader;
			std::unordered_map<std::string, Graphics::Sprite*> _Sprites;
		};
	}
}

#endif    