#ifndef LDL_Platforms_Windows_Graphics_DirectDraw_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_DirectDraw_WindowImpl_hpp

#include <LDL/Graphics/Window.hpp>
#include "../MainWindow.hpp"
#include "../WindowImpl.hpp"
#include "../../DirectX/DirectDraw.hpp"

namespace LDL
{
	namespace Graphics
	{
		class WindowImplDirectDraw: public WindowImpl
		{
		public:
			WindowImplDirectDraw(const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~WindowImplDirectDraw();
			bool Running();
			void Present();
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
			IDirectDraw*        _DirectDraw;
			IDirectDrawSurface* _Primary;
			IDirectDrawSurface* _Screen;
			IDirectDrawClipper* _Clipper;
			MainWindow          _Window;
		};
	}
}

#endif  
