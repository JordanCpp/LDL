#ifndef LDL_Cpp_Surface_hpp
#define LDL_Cpp_Surface_hpp

#include <LDL/Low/Creators.hpp>
#include <LDL/Cpp/RContext.hpp>
#include <LDL/Cpp/Window.hpp>

class LDL_Surface
{
public:
	LDL_Surface(LDL_RenderContext* renderContext, LDL_Window* window, const LDL_Point2u& size, uint8_t bpp)
	{
		_Surface = LDL_SurfaceCreate(renderContext->GetRenderContext(), window->GetWindow(), size, bpp);
	}

	LDL_Surface(LDL_RenderContext* renderContext, LDL_Window* window, const LDL_Point2u& size, uint8_t LDL_FAR* bytes, uint8_t bpp)
	{
		_Surface = LDL_SurfaceCreate(renderContext->GetRenderContext(), window->GetWindow(), size, bytes, bpp);
	}

	~LDL_Surface()
	{
		LDL_Destroy(_Surface);
	}

	LDL_ISurface* GetSurface()
	{
		return _Surface;
	}

	uint8_t LDL_FAR* Pixels()
	{
		return _Surface->Pixels();
	}

	uint8_t Bpp()
	{
		return _Surface->Bpp();
	}

	const LDL_Point2u& Size()
	{
		return _Surface->Size();
	}
private:
	LDL_ISurface* _Surface;
};

#endif
