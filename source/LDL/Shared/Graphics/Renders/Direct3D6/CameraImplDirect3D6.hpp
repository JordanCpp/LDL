#ifndef LDL_Graphics_Direct3D6_CameraImpl_hpp
#define LDL_Graphics_Direct3D6_CameraImpl_hpp

#include "RenderImplDirect3D6.hpp"
#include "../../Impls/CameraImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class CameraImplDirect3D6 : public CameraImpl
		{
		public:
			CameraImplDirect3D6(RenderImpl* renderImpl, const Math::Vec2u& pos, const Math::Vec2u& size);
			const Math::Vec2u& Pos();
			const Math::Vec2u& Size();
			void Pos(const Math::Vec2u& pos);
			void Size(const Math::Vec2u& size);
		private:
			RenderImpl* _impl;
			Math::Vec2u _pos;
			Math::Vec2u _size;
		};
	}
}

#endif   
