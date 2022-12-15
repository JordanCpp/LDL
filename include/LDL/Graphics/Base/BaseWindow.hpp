#ifndef LDL_Graphics_BaseWindow_hpp
#define LDL_Graphics_BaseWindow_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		class BaseWindow
		{
		public:
			BaseWindow(const Point2u& pos, const Point2u& size, const std::string& title);
			const Point2u& Pos();
			const Point2u& Size();
			const std::string& Title();
			void Title(const std::string& source);
		private:
			Point2u _Pos;
			Point2u _Size;
			std::string _Title;
		};
	}
}

#endif    