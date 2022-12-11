#ifndef LDL_Graphics_GpuWindow_hpp
#define LDL_Graphics_GpuWindow_hpp

#include <string>
#include <LDL/Events/Event.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Enums/WindowMode.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GpuWindowImpl;

		class GpuWindow
		{
		public:
			GpuWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~GpuWindow();
			void Present();
			bool GetEvent(LDL::Events::Event& event);
			bool WaitEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const LDL::Graphics::Point2u& Size();
			const LDL::Graphics::Point2u& Pos();
		private:
			GpuWindowImpl* _GpuWindowImpl;
		};
	}
}

#endif 