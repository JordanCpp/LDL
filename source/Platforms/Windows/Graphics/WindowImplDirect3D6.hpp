#ifndef LDL_Platforms_Windows_Graphics_WindowImplDirect3D6_hpp
#define LDL_Platforms_Windows_Graphics_WindowImplDirect3D6_hpp

#include "MainWindow.hpp"
#include "../../WindowImpl.hpp"
#include <LDL/Graphics/Window.hpp>

namespace LDL
{
	namespace Graphics
	{
		class WindowImplDirect3D6 : public WindowImpl
		{
		public:
			WindowImplDirect3D6(const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~WindowImplDirect3D6();
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
			void* NativeHandle();
		private:
			MainWindow _Window;
		};
	}
}

#endif  
