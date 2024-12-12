#ifndef LDL_Graphics_OpenGL3_TexturePainter_hpp
#define LDL_Graphics_OpenGL3_TexturePainter_hpp

#include <LDL/APIs/OpenGL/OpenGL3_0.hpp>
#include "ShaderLoaderOpenGL3.hpp"
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Math/Mat4.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TexturePainter
		{
		public:
			TexturePainter(ShaderLoader* shaderLoader);
			void Draw(LDL::Math::Mat4f proj, Texture * texture);
		private:
			ShaderLoader* _ShaderLoader;
			GLuint        _ShaderProgram;
			GLuint        _VertexBufferObject;
			GLuint        _VertexArraysObject;
			GLuint        _ElementBufferObject;
		};
	}
}

#endif    
