#ifndef LDL_Platforms_Windows_Graphics_CpuWindow_hpp
#define LDL_Platforms_Windows_Graphics_CpuWindow_hpp

#include <LDL/Platforms/Windows/Graphics/MainWindow.hpp>

namespace LDL
{
	namespace Graphics
	{
		namespace Windows
		{
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
				LDL::Graphics::Windows::MainWindow _Window;
				BITMAPINFO _BITMAPINFO;
			};
		}
	}
}

#endif    