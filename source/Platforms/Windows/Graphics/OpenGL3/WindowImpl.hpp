#ifndef LDL_Platforms_Windows_Graphics_OpenGL1_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_OpenGL1_WindowImpl_hpp

#include <LDL/Graphics/Window.hpp>
#include "../MainWindow.hpp"
#include <LDL/OpenGL/OpenGLLoader.hpp>

namespace LDL
{
	namespace Graphics
	{
		class WindowImpl
		{
		public:
			WindowImpl(const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~WindowImpl();
			bool Running();
			void PollEvents();
			void Present();
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
			HGLRC _HGLRC;
			OpenGLLoader _OpenGLLoader;
		};
	}
}

#endif  