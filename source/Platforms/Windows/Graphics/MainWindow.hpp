#ifndef LDL_Platforms_Windows_Graphics_MainWindow_hpp
#define LDL_Platforms_Windows_Graphics_MainWindow_hpp

#include "../Windows.hpp"
#include <LDL/Graphics/Base/BaseWindow.hpp>
#include <LDL/Events/Eventer.hpp>
#include <LDL/Enums/WindowMode.hpp>

namespace LDL
{
	namespace Graphics
	{
		namespace Windows
		{
			class MainWindow
			{
			public:
				MainWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, size_t mode);
				~MainWindow();
				bool GetEvent(LDL::Events::Event& event);
				bool WaitEvent(LDL::Events::Event& event);
				void StopEvent();
				void Title(const std::string& title);
				const std::string& Title();
				const LDL::Graphics::Point2u& Size();
				const LDL::Graphics::Point2u& Pos();
			private:
				size_t ConvertKey(size_t key);
				static LRESULT CALLBACK WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam);
				LRESULT CALLBACK Handler(UINT Message, WPARAM WParam, LPARAM LParam);
				LDL::Graphics::BaseWindow _BaseWindow;
				LDL::Events::Eventer _Eventer;
				WNDCLASS  _WNDCLASS;
				HINSTANCE _HINSTANCE;
				MSG       _MSG;
				ATOM      _ATOM;
			public:
				HWND _HWND;
				HDC  _HDC;
			};
		}
	}
}

#endif   