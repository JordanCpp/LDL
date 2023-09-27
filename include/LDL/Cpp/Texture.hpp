#ifndef LDL_Cpp_Texture_hpp
#define LDL_Cpp_Texture_hpp

#include <LDL/Low/Creators.hpp>

class LDL_Texture
{
public:
	LDL_Texture(LDL_RenderContext* renderContext, const LDL_Vec2u& size, uint8_t* pixels, uint8_t bpp)
	{
		_Texture = LDL_TextureCreate(renderContext->GetRenderContext(), size, pixels, bpp);
	}

	~LDL_Texture()
	{
		LDL_Destroy(_Texture);
	}

	LDL_ITexture* GetTexture()
	{
		return _Texture;
	}

	const LDL_Vec2u& Size()
	{
		return _Texture->Size();
	}

	const LDL_Vec2u& Quad()
	{
		return _Texture->Quad();
	}
private:
	LDL_ITexture* _Texture;
};

#endif
