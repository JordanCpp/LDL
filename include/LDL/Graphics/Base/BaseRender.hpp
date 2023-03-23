#ifndef LDL_Graphics_BaseRender_hpp
#define LDL_Graphics_BaseRender_hpp

#include <LDL/Config.hpp>
#include <LDL/Graphics/Primitives/Color.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_EXPORT BaseRender
		{
		public:
			BaseRender(const Point2u& size);
			const Point2u& Size();
			const LDL::Graphics::Color& Color();
			void Color(const LDL::Graphics::Color& color);
		public:
			Point2u _Size;
			LDL::Graphics::Color _Current;
		};
	}
}

#endif    