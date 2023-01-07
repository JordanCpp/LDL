#ifndef LDL_OpenGL_OpenGL1_1_hpp
#define LDL_OpenGL_OpenGL1_1_hpp

#include <LDL/OpenGL/OpenGL1_0.hpp>

typedef	void	(OPENGL_API_CALL pglVertexPointer)(GLint	size, GLenum	type, GLsizei	stride, const	GLvoid* pointer);

extern	pglVertexPointer* glVertexPointer;

#endif     