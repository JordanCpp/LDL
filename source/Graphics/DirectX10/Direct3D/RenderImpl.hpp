#ifndef LDL_Graphics_DirectX10_Direct3D_RenderImpl_hpp
#define LDL_Graphics_DirectX10_Direct3D_RenderImpl_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Base/BaseRender.hpp>

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl
		{
		public:
			RenderImpl(RenderContextImpl* renderContextImpl, Window* window);
			~RenderImpl();
			void RenderImpl::Buffer(uint8_t* dst);
			void Mode2D();
			void Begin();
			void End();
			const Point2u& Size();
			const LDL::Graphics::Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Pixel(const Point2u& pos);
			void Fill(const Point2u& pos, const Point2u& size);
			void Line(const Point2u& pos1, const Point2u& pos2);
			void Draw(Texture* image, const Point2u& pos, const Point2u& size);
			void Draw(Texture* image, const Point2u& pos);
			void Draw(Surface* image, const Point2u& pos, const Point2u& size);
			void Draw(Surface* image, const Point2u& pos);
			void Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize);
		private:
			void Initialization();
			void Deinitialization();
			Window* _Window;
			BaseRender _BaseRender;
		public:
			RenderContextImpl* _RenderContextImpl;
		};
	}
}

#endif    