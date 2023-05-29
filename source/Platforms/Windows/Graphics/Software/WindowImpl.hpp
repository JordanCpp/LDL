#ifndef LDL_Platforms_Windows_Graphics_Software_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_Software_WindowImpl_hpp

#include "../MainWindow.hpp"

namespace LDL
{
	namespace Graphics
	{
		class WindowImpl
		{
		public:
			WindowImpl(const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~WindowImpl();
			void Present(uint8_t* pixels, uint8_t bytesPerPixel);
			bool Running();
			void PollEvents();
			bool GetEvent(LDL::Events::Event& event);
			bool WaitEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Math::Vec2u& Size();
			const Math::Vec2u& Pos();
			HWND Hwnd();
		private:
			MainWindow _Window;
			BITMAPINFO _BITMAPINFO;
		};
	}
}

#endif    