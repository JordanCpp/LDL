#ifndef LDL_Platforms_Windows_Graphics_GpuWindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_GpuWindowImpl_hpp

#include <LDL/Graphics/Gpu/GpuWindow.hpp>
#include "../MainWindow.hpp"

namespace LDL
{
	namespace Graphics
	{
		class GpuWindowImpl
		{
		public:
			GpuWindowImpl(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~GpuWindowImpl();
			void Present();
			bool GetEvent(LDL::Events::Event& event);
			bool WaitEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const LDL::Graphics::Point2u& Size();
			const LDL::Graphics::Point2u& Pos();
		private:
			LDL::Graphics::Windows::MainWindow _Window;
			HGLRC _HGLRC;
		};
	}
}

#endif  