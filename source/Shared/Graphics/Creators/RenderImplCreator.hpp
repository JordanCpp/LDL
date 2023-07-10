#ifndef LDL_Graphics_Creators_RenderImplCreator_hpp
#define LDL_Graphics_Creators_RenderImplCreator_hpp

#include <LDL/Graphics/Window.hpp>
#include "../RenderImpl.hpp"
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Math/Vec2.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		namespace Creators
		{
			class RenderImplCreator
			{
			public:
				RenderImpl* Create(RenderContext* renderContext, Window* window);
			private:
			};
		}
	}
}

#endif    