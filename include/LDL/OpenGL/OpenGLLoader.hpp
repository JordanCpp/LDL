#ifndef LDL_OpenGL_OpenGLLoader_hpp
#define LDL_OpenGL_OpenGLLoader_hpp

#include <LDL/Graphics/Gpu/GpuFunctions.hpp>

namespace LDL
{
	class OpenGLLoader
	{
	public:
		OpenGLLoader(size_t major = 1, size_t minor = 0);
		~OpenGLLoader();
		size_t Major();
		size_t Minor();
		void Init_1_0();
		void Init_1_1();
	private:
		LDL::Graphics::GpuFunctions _GpuFunctions;
		size_t _Major;
		size_t _Minor;
	};
}

#endif      