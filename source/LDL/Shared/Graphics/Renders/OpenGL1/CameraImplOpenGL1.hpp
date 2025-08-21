#ifndef LDL_Graphics_OpenGL1_CameraImpl_hpp
#define LDL_Graphics_OpenGL1_CameraImpl_hpp

#include "RenderImplOpenGL1.hpp"
#include "../../Impls/CameraImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class CameraImplOpenGL1 : public CameraImpl
		{
		public:
			CameraImplOpenGL1(RenderImpl* renderImpl, const Math::Vec2u& pos, const Math::Vec2u& size);
			const Math::Vec2u& Pos();
			const Math::Vec2u& Size();
			void Pos(const Math::Vec2u& pos);
			void Size(const Math::Vec2u& size);
		private:
			RenderImpl*      _renderImpl;
			LDL::Math::Vec2u _pos;
			LDL::Math::Vec2u _size;
		};
	}
}

#endif   
