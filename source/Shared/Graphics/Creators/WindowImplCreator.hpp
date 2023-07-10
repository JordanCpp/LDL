#ifndef LDL_Graphics_Creators_WindowImplCreator_hpp
#define LDL_Graphics_Creators_WindowImplCreator_hpp

#if defined(_WIN32)
#include "../source/Platforms/Windows/Graphics/WindowImpl.hpp"
#elif defined(__unix__)
#include "../source/Platforms/Linux/Graphics/WindowImpl.hpp"
#endif

#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Math/Vec2.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		namespace Creators
		{
			class WindowImplCreator
			{
			public:
				WindowImpl* Create(RenderContext* renderContext, const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode);
			private:
			};
		}
	}
}

#endif    