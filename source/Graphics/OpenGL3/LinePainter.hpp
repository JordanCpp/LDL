#ifndef LDL_Graphics_OpenGL3_LinePainter_hpp
#define LDL_Graphics_OpenGL3_LinePainter_hpp

#include <LDL/OpenGL/OpenGL3_0.hpp>
#include <LDL/Math/Mat4f.hpp>
#include <LDL/Math/Vec3f.hpp>
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
			void Draw(LDL::Math::Mat4f proj, LDL::Math::Vec3f start, LDL::Math::Vec3f end, LDL::Math::Vec3f color);
		private:
			LDL::Math::Vec3f _Lines[2];
			LDL::Math::Vec3f _Color;
			GLuint _ShaderProgram;
			GLuint _VertexBufferObject;
			GLuint _VertexArraysObject;
			ShaderLoader* _ShaderLoader;
		};
	}
}

#endif    