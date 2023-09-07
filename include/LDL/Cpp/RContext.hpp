#ifndef LDL_Cpp_RContext_hpp
#define LDL_Cpp_RContext_hpp

#include <LDL/Low/Creators.hpp>

class LDL_RenderContext
{
public:
	LDL_RenderContext()
	{
		_RenderContext = RenderContextCreate();
	}

	~LDL_RenderContext()
	{
		Destroy(_RenderContext);
	}

	LDL_IRenderContext* GetRenderContext()
	{
		return _RenderContext;
	}
private:
	LDL_IRenderContext* _RenderContext;
};

#endif
