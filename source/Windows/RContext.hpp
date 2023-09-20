#ifndef LDL_Windows__RContext_hpp
#define LDL_Windows__RContext_hpp

#include <LDL/Low/Abstract.hpp>

class LDL_ImpRenderContext : public LDL_IRenderContext
{
public:
	LDL_ImpRenderContext(size_t mode);
	size_t Mode();
private:
	size_t _Mode;
};

#endif
