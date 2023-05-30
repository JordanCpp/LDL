#ifndef LDL_Graphics_OpenGL3_LinePainter_hpp
#define LDL_Graphics_OpenGL3_LinePainter_hpp

#include <LDL/OpenGL/OpenGL3_0.hpp>
#include <LDL/Math/Mat4.hpp>
#include <LDL/Math/Vec3.hpp>
#include "ShaderLoader.hpp"

namespace LDL
{
	namespace Graphics
	{
		class LinePainter
		{
		public:
			LinePainter(ShaderLoader* shaderLoader);
			~LinePainter();
			void Draw(Math::Mat4f proj, Math::Vec3f start, Math::Vec3f end, Math::Vec3f color);
		private:
			Math::Vec3f _Lines[2];
			Math::Vec3f _Color;
			GLuint _ShaderProgram;
			GLuint _VertexBufferObject;
			GLuint _VertexArraysObject;
			ShaderLoader* _ShaderLoader;
		};
	}
}

#endif    