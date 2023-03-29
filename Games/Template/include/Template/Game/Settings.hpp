#ifndef Template_Game_Settings_hpp
#define Template_Game_Settings_hpp

#include <string>
#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace Template
{
	namespace Game
	{
		class Settings
		{
		public:
			Settings();
			const std::string& Path();
			void Path(const std::string& path);
			const std::string& Title();
			void Title(const std::string& title);
			const LDL::Graphics::Point2u& Size();
			void Size(const LDL::Graphics::Point2u& size);
			size_t Fps();
			void Fps(size_t fps);
		private:
			std::string _Path;
			std::string _Title;
			LDL::Graphics::Point2u _Size;
			size_t _Fps;
		};
	}
}

#endif    