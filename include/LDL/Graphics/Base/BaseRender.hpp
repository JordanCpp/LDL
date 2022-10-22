#ifndef LDL_Graphics_BaseRender_hpp
#define LDL_Graphics_BaseRender_hpp

#include <LDL/Graphics/Primitives/Color.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class BaseRender
		{
		public:
			BaseRender(const LDL::Graphics::Point2u& size);
			const LDL::Graphics::Point2u& Size();
			const LDL::Graphics::Color& Color();
			void Color(const LDL::Graphics::Color& color);
		private:
			LDL::Graphics::Point2u _Size;
			LDL::Graphics::Color _Current;
		};
	}
}

#endif    