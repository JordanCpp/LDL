#ifndef LDL_Platforms_Windows_Graphics_MainWindow_hpp
#define LDL_Platforms_Windows_Graphics_MainWindow_hpp

#include <LDL/Graphics/Base/BaseWindow.hpp>
#include <LDL/Events/Eventer.hpp>
#include <LDL/Enums/WindowMode.hpp>

#include <X11/Xlib.h>

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
		    BaseWindow _BaseWindow;
			size_t ConvertKey(size_t key);
			LDL::Events::Eventer _Eventer;
			Display* _Display;
			int _ScreenId;
			Screen* _Screen;
			Window _Window;
		};
	}
}

#endif   