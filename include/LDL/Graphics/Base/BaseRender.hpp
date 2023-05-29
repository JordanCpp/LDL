#ifndef LDL_Graphics_BaseRender_hpp
#define LDL_Graphics_BaseRender_hpp

#include <LDL/Config.hpp>
#include <LDL/Graphics/Color.hpp>
#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_EXPORT BaseRender
		{
		public:
			BaseRender(const Math::Vec2u& size);
			const Math::Vec2u& Size();
			const LDL::Graphics::Color& Color();
			void Color(const LDL::Graphics::Color& color);
		public:
			LDL::Math::Vec2u _Size;
			LDL::Graphics::Color _Current;
		};
	}
}

#endif    