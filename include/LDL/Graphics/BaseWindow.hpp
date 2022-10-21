#ifndef LDL_Graphics_BaseWindow_hpp
#define LDL_Graphics_BaseWindow_hpp

#include <LDL/Graphics/Point2u.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		class BaseWindow
		{
		public:
			BaseWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title);
			const LDL::Graphics::Point2u& Pos();
			const LDL::Graphics::Point2u& Size();
			const std::string& Title();
			void Title(const std::string& source);
		private:
			LDL::Graphics::Point2u _Pos;
			LDL::Graphics::Point2u _Size;
			std::string _Title;
		};
	}
}

#endif    