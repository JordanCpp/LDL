#ifndef LDL_Platforms_Windows_Graphics_DX5Window_hpp
#define LDL_Platforms_Windows_Graphics_DX5Window_hpp

#include <LDL/Graphics/IGpuWindow.hpp>
#include <LDL/Enums/WindowMode.hpp>
#include "../MainWindow.hpp"

namespace LDL
{
	namespace Graphics
	{
		namespace Windows
		{
			class DX5Window : public LDL::Graphics::IGpuWindow
			{
			public:
				DX5Window(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, size_t mode);
				~DX5Window();
				void Present();
				bool GetEvent(LDL::Events::Event& event);
				bool WaitEvent(LDL::Events::Event& event);
				void StopEvent();
				void Title(const std::string& title);
				const std::string& Title();
				const LDL::Graphics::Point2u& Size();
				const LDL::Graphics::Point2u& Pos();
				HWND Hwnd();
			private:
				LDL::Graphics::Windows::MainWindow _Window;
			};
		}
	}
}

#endif  