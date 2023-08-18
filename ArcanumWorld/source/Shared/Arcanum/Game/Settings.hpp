#ifndef Arcanum_Game_Settings_hpp
#define Arcanum_Game_Settings_hpp

#include <string>
#include <LDL/Math/Vec2.hpp>

namespace Arcanum
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
			const LDL::Math::Vec2u& Size();
			void Size(const LDL::Math::Vec2u& size);
			size_t Fps();
			void Fps(size_t fps);
			size_t Render();
			void Render(size_t render);
			const std::string& DatFiles();
			void DatFiles(const std::string& value);
			const std::string& DataFiles();
			void DataFiles(const std::string& value);
		private:
			std::string _Path;
			std::string _Title;
			std::string _DatFiles;
			std::string _DataFiles;
			LDL::Math::Vec2u _Size;
			size_t _Fps;
			size_t _Render;
		};
	}
}

#endif    