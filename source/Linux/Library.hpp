#ifndef LDL_Linux_Library_hpp
#define LDL_Linux_Library_hpp

#include <LDL/Low/Abstract.hpp>

class LDL_Library : public LDL_ILibrary
{
public:
	LDL_Library(const char* path);
	~LDL_Library();
	LDL_VoidFuncPtr Function(const char* name);
private:
    void* _Library;
};

#endif
