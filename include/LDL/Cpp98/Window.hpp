#ifndef LDL_Cpp98_Window_hpp
#define LDL_Cpp98_Window_hpp

#include <LDL/Creators.hpp>

namespace LDL
{
	namespace Graphics
	{
		class Window
		{
		public:
			Window()
			{
				_Window = WindowCreate();
			}

			~Window()
			{
				Destroy(_Window);
			}
		private:
			LDL_IWindow* _Window;
		};
	}
}

#endif
