#ifndef LDL_Platforms_Windows_Graphics_MainWindow_hpp
#define LDL_Platforms_Windows_Graphics_MainWindow_hpp

#include "../Windows.hpp"
#include <LDL/Shared/Graphics/Base/BaseWindow.hpp>
#include <LDL/Shared/Events/Eventer.hpp>
#include <LDL/Enums/WindowMode.hpp>

namespace LDL
{
	namespace Graphics
	{
		class MainWindow
		{
		public:
			MainWindow(const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode);
			~MainWindow();
			bool Running();
			void PollEvents();
			bool GetEvent(LDL::Events::Event& event);
			bool WaitEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Math::Vec2u& Size();
			const Math::Vec2u& Pos();
		private:
			uint8_t ConvertKey(size_t key);
			static LRESULT CALLBACK WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam);
			LRESULT CALLBACK Handler(UINT Message, WPARAM WParam, LPARAM LParam);
			BaseWindow           _baseWindow;
			LDL::Events::Eventer _eventer;
			WNDCLASS             _windowClass;
			HINSTANCE            _instance;
			MSG                  _msg;
			ATOM                 _atom;
		public:
			HWND _HWND;
			HDC  _HDC;
		};
	}
}

#endif   
