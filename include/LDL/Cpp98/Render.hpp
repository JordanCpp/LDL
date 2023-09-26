#ifndef LDL_Cpp98_Render_hpp
#define LDL_Cpp98_Render_hpp

#include <LDL/Cpp98/RenderContext.hpp>
#include <LDL/Cpp98/Window.hpp>
#include <LDL/Cpp/Render.hpp>

namespace LDL
{
	namespace Graphics
	{
		class Render: public LDL_Render
		{
		public:
			Render(LDL_RenderContext* context, LDL_Window* window) :
				LDL_Render(context, window)
			{
			}
		private:
		};
	}
}

#endif
