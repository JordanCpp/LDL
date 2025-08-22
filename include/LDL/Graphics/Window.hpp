#ifndef LDL_Graphics_Window_hpp
#define LDL_Graphics_Window_hpp

#include <string>
#include <LDL/Events/Event.hpp>
#include <LDL/Math/Vec2.hpp>
#include <LDL/Enums/WindowMode.hpp>
#include <LDL/Graphics/RenderContext.hpp>

namespace LDL
{
	namespace Graphics
	{
		class WindowImpl;

		class LDL_LIBRARY Window
		{
		public:
			Window(RenderContext* renderContext, const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode = Enums::WindowMode::Resized);
			~Window();
			bool Running();
			void PollEvents();
			bool GetEvent(Events::Event& event);
			bool WaitEvent(Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Math::Vec2u& Size();
			const Math::Vec2u& Pos();
			WindowImpl* GetWindowImpl();
			void* NativeHandle();
		private:
			WindowImpl* _impl;
		};
	}
}

#endif 
