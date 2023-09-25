#ifndef LDL_Cpp_OpenGLLibrary_hpp
#define LDL_Cpp_OpenGLLibrary_hpp

#include <LDL/Low/Creators.hpp>

class LDL_OpenGLLibrary
{
public:
	LDL_OpenGLLibrary()
	{
		_Library = OpenGLLibraryCreate();
	}

	~LDL_OpenGLLibrary()
	{
		Destroy(_Library);
	}

	LDL_VoidFuncPtr Function(const char* name)
	{
		return _Library->Function(name);
	}
private:
	LDL_IOpenGLLibrary* _Library;
};

#endif
