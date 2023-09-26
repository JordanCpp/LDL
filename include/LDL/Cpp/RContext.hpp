#ifndef LDL_Cpp_RContext_hpp
#define LDL_Cpp_RContext_hpp

#include <LDL/Low/Creators.hpp>

class LDL_RenderContext
{
public:
	LDL_RenderContext(size_t mode = LDL_RenderMode::OpenGL1)
	{
		_RenderContext = LDL_RenderContextCreate(mode);
	}

	~LDL_RenderContext()
	{
		LDL_Destroy(_RenderContext);
	}

	LDL_IRenderContext* GetRenderContext()
	{
		return _RenderContext;
	}
private:
	LDL_IRenderContext* _RenderContext;
};

#endif
