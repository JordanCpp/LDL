#ifndef LDL_Graphics_CpuWindow_hpp
#define LDL_Graphics_CpuWindow_hpp

#include <string>
#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Events/Event.hpp>
#include <LDL/Enums/WindowMode.hpp>

namespace LDL
{
	namespace Graphics
	{
		class CpuWindowImpl;

		class CpuWindow
		{
		public:
			CpuWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~CpuWindow();
			void Present(uint8_t* pixels);
			bool GetEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const LDL::Graphics::Point2u& Size();
			const LDL::Graphics::Point2u& Pos();
		private:
			CpuWindowImpl* _CpuWindowImpl;
		};
	}
}

#endif    