#ifndef LDL_Platforms_Windows_Graphics_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_WindowImpl_hpp

#include <LDL/Graphics/Window.hpp>
#include "../MainWindow.hpp"
#include "ContextImpl.hpp"
#include <LDL/OpenGL/OpenGLLoader.hpp>

namespace LDL
{
	namespace Graphics
	{
		class WindowImpl
		{
		public:
			WindowImpl(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~WindowImpl();
			void Present();
			bool GetEvent(LDL::Events::Event& event);
			bool WaitEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Point2u& Size();
			const Point2u& View();
			const Point2u& Pos();
		private:
			MainWindow _Window;
			ContextImpl _ContextImpl;
			OpenGLLoader _OpenGLLoader;
		};
	}
}

#endif  