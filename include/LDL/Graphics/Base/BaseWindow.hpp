#ifndef LDL_Graphics_BaseWindow_hpp
#define LDL_Graphics_BaseWindow_hpp

#include <LDL/Config.hpp>
#include <LDL/Math/Vec2.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		class LDL_EXPORT BaseWindow
		{
		public:
			BaseWindow(const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title);
			const Math::Vec2u& Pos();
			const Math::Vec2u& Size();
			void Size(const Math::Vec2u& size);
			const std::string& Title();
			void Title(const std::string& source);
		private:
			LDL::Math::Vec2u _Pos;
			LDL::Math::Vec2u _Size;
			LDL::Math::Vec2u _View;
			std::string _Title;
		};
	}
}

#endif    