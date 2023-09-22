#ifndef LDL_WindowsLibrary_hpp
#define LDL_Windows_Library_hpp

#include <LDL/Low/Abstract.hpp>
#include "WinX.hpp"

class LDL_Library : public LDL_ILibrary
{
public:
	LDL_Library(const char* path);
	~LDL_Library();
	LDL_VoidFuncPtr Function(const char* name);
private:
	HMODULE _HMODULE;
};

#endif
