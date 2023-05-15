#ifndef LDL_Graphics_TextureBatcher_hpp
#define LDL_Graphics_TextureBatcher_hpp

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl;

		class LDL_EXPORT Texture : public LDL::Core::FastPimpl
		{
		public:
			Texture(RenderContext* renderContext, const Point2u& size, uint8_t* pixels, uint8_t bytesPerPixel);
			~Texture();
			const Point2u& Size();
			TextureImpl* GetTextureImpl();
		private:
			TextureImpl* _TextureImpl;
		};
	}
}

#endif    