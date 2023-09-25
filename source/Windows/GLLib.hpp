#ifndef LDL_Windows_GLLib_hpp
#define LDL_Windows_GLLib_hpp

#include "Library.hpp"

class LDL_ImpOpenGLLibrary : public LDL_IOpenGLLibrary
{
public:
	LDL_ImpOpenGLLibrary();
	LDL_VoidFuncPtr Function(const char* name);
private:
	LDL_Library _Library;
};

#endif