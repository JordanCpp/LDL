#ifndef LDL_Graphics_Software_CameraImpl_hpp
#define LDL_Graphics_Software_CameraImpl_hpp

#include "RenderImpl.hpp"
#include <LDL/Graphics/Primitives/Point2i.hpp>

namespace LDL
{
	namespace Graphics
	{
		class CameraImpl
		{
		public:
			CameraImpl(RenderImpl* renderImpl, const Point2u& pos, const Point2u& size);
			const Point2u& Pos();
			const Point2u& Size();
			void Pos(const Point2u& pos);
			void Size(const Point2u& size);
		private:
			RenderImpl* _RenderImpl;
			Point2u _Pos;
			Point2u _Size;
		};
	}
}

#endif    