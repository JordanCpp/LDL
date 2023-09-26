#ifndef LDL_Renders_GL1Texture_hpp
#define LDL_Renders_GL1Texture_hpp

#include <LDL/Low/Abstract.hpp>

class LDL_GL1Texture : public LDL_ITexture
{
public:
	LDL_GL1Texture(LDL_IRenderContext* renderContext, const LDL_Point2u& size, uint8_t* pixels, uint8_t bpp);
	~LDL_GL1Texture();
	const LDL_Point2u& Size();
	const LDL_Point2u& Quad();
	size_t Id();
private:
	LDL_IRenderContext* _RenderContext;
	size_t  _Id;
	LDL_Point2u _Size;
	LDL_Point2u _Quad;
};

#endif