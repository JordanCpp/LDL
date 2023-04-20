#ifndef LDL_Graphics_OpenGL3_TexturePainter_hpp
#define LDL_Graphics_OpenGL3_TexturePainter_hpp

#include <LDL/OpenGL/OpenGL3_0.hpp>
#include "ShaderLoader.hpp"
#include <LDL/Graphics/Texture.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TexturePainter
		{
		public:
			TexturePainter(ShaderLoader* shaderLoader);
			void Draw(Texture * texture);
		private:
			ShaderLoader* _ShaderLoader;
			GLuint _ShaderProgram;
			GLuint _VertexBufferObject;
			GLuint _VertexArraysObject;
			GLuint _ElementBufferObject;
		};
	}
}

#endif    