#ifndef LDL_Graphics_Renders_Glide_CameraImplGlide_hpp
#define LDL_Graphics_Renders_Glide_CameraImplGlide_hpp

#include "RenderImplGlide.hpp"
#include "../../Impls/CameraImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class CameraImplGlide : public CameraImpl
		{
		public:
			CameraImplGlide(RenderImpl* renderImpl, const Math::Vec2u& pos, const Math::Vec2u& size);
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
