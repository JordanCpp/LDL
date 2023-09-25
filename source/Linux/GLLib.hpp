#ifndef LDL_Linux_GLLib_hpp
#define LDL_Linux_GLLib_hpp

#include <LDL/Low/Abstract.hpp>

class LDL_ImpOpenGLLibrary : public LDL_IOpenGLLibrary
{
public:
	LDL_VoidFuncPtr Function(const char* name);
private:
};

#endif