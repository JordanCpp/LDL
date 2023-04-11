#ifndef LDL_Graphics_OpenGL3_TexturePainter_hpp
#define LDL_Graphics_OpenGL3_TexturePainter_hpp

#include "ShaderLoader.hpp"

namespace LDL
{
	namespace Graphics
	{
		class TexturePainter
		{
		public:
			TexturePainter(ShaderLoader* shaderLoader);
		private:
			ShaderLoader* _ShaderLoader;
		};
	}
}

#endif    