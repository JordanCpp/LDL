#ifndef LDL_Platforms_Windows_Graphics_DirectX9_Direct3D_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_DirectX9_Direct3D_WindowImpl_hpp

#include <LDL/Graphics/Window.hpp>
#include <LDL/Enums/WindowMode.hpp>
#include "../MainWindow.hpp"
#include "../WindowImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
			class WindowImplDirect3D9 : public WindowImpl
			{
			public:
				WindowImplDirect3D9(const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Fixed);
				~WindowImplDirect3D9();
				void Present(uint8_t* pixels, uint8_t bytesPerPixel);
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
			};
		}
}

#endif  