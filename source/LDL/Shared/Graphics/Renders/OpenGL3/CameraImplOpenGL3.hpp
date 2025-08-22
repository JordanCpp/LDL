#ifndef LDL_Graphics_OpenGL3_CameraImpl_hpp
#define LDL_Graphics_OpenGL3_CameraImpl_hpp

#include "RenderImplOpenGL3.hpp"
#include "../../Impls/CameraImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class CameraImplOpenGL3 : public CameraImpl
		{
		public:
			CameraImplOpenGL3(RenderImpl* renderImpl, const Math::Vec2u& pos, const Math::Vec2u& size);
			const Math::Vec2u& Pos();
			const Math::Vec2u& Size();
			void Pos(const Math::Vec2u& pos);
			void Size(const Math::Vec2u& size);
		private:
			RenderImpl* _renderImpl;
			Math::Vec2u _pos;
			Math::Vec2u _size;
		};
	}
}

#endif   
