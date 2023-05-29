#ifndef LDL_Graphics_DirectX5_Direct3D_RenderImpl_hpp
#define LDL_Graphics_DirectX5_Direct3D_RenderImpl_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Base/BaseRender.hpp>

#include <windows.h>
#include <ddraw.h>
#include <d3d.h>    
#include <d3drm.h> 

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl
		{
		public:
			RenderImpl(Window* window);
			~RenderImpl();
			void Buffer(uint8_t* dst);
			void Begin();
			void End();
			const Math::Vec2u& Size();
			const Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Pixel(const Math::Vec2u& pos);
			void Fill(const Math::Vec2u& pos, const Math::Vec2u& size);
			void Line(const Math::Vec2u& pos1, const Math::Vec2u& pos2);
			void Draw(Texture* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Texture* image, const Math::Vec2u& pos);
			void Draw(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Surface* image, const Math::Vec2u& pos);
			void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
		private:
			LDL::Graphics::Window* _Window;
			LDL::Graphics::BaseRender _BaseRender;
			LPDIRECT3DRM _Direct3Drm = NULL;
			LPDIRECTDRAWCLIPPER _DirectDrawClipper = NULL;
			LPDIRECT3DRMDEVICE _Direct3DrmDevice = NULL;
			GUID* _GUID = NULL;
		};
	}
}

#endif    