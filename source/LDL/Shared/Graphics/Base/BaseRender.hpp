#ifndef LDL_Graphics_BaseRender_hpp
#define LDL_Graphics_BaseRender_hpp

#include <LDL/Graphics/Color.hpp>
#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_LIBRARY BaseRender
		{
		public:
			BaseRender(const Math::Vec2u& size);
			const Math::Vec2u& Size();
			const Graphics::Color& Color();
			void Color(const Graphics::Color& color);
		public:
			Graphics::Color _current;
			Math::Vec2u     _size;
		};
	}
}

#endif    
