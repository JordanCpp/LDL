#ifndef LDL_Platforms_Windows_Graphics_DirectDraw_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_DirectDraw_WindowImpl_hpp

#include <LDL/Graphics/Window.hpp>
#include "../MainWindow.hpp"
#include <ddraw.h>

namespace LDL
{
	namespace Graphics
	{
		class WindowImpl
		{
		public:
			WindowImpl(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~WindowImpl();
			void Present(uint8_t* pixels, uint8_t bytesPerPixel);
			bool GetEvent(LDL::Events::Event& event);
			bool WaitEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Point2u& Size();
			const Point2u& View();
			const Point2u& Pos();
			HWND Hwnd();
		private:
			MainWindow _Window;
		};
	}
}

#endif  