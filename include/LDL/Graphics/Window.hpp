#ifndef LDL_Graphics_Window_hpp
#define LDL_Graphics_Window_hpp

#include <string>
#include <LDL/Events/Event.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Enums/WindowMode.hpp>
#include <LDL/Core/FastPimpl.hpp>

namespace LDL
{
	namespace Graphics
	{
		class WindowImpl;

		class LDL_EXPORT Window : public LDL::Core::FastPimpl
		{
		public:
			Window(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~Window();
			bool Running();
			void PollEvents();
			bool GetEvent(LDL::Events::Event& event);
			bool WaitEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Point2u& Size();
			const Point2u& Pos();
			WindowImpl* GetWindowImpl();
		private:
			WindowImpl* _WindowImpl;
		};
	}
}

#endif 