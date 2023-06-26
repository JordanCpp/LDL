#ifndef LDL_Graphics_Software_CameraImpl_hpp
#define LDL_Graphics_Software_CameraImpl_hpp

#include "RenderImplSoftware.hpp"
#include <LDL/Math/Vec2.hpp>
#include "../CameraImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class CameraImplSoftware : public CameraImpl
		{
		public:
			CameraImplSoftware(RenderImpl* renderImpl, const Math::Vec2u& pos, const Math::Vec2u& size);
			const Math::Vec2u& Pos();
			const Math::Vec2u& Size();
			void Pos(const Math::Vec2u& pos);
			void Size(const Math::Vec2u& size);
		private:
			RenderImpl* _RenderImpl;
			LDL::Math::Vec2u _Pos;
			LDL::Math::Vec2u _Size;
		};
	}
}

#endif    