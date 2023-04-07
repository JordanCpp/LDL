#ifndef LDL_OpenGL_OpenGLUtility_hpp
#define LDL_OpenGL_OpenGLUtility_hpp

#include <LDL/OpenGL/OpenGLTypes.hpp>

void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar);

void gluLookAt(GLfloat eyex, GLfloat eyey, GLfloat eyez, GLfloat centerx, GLfloat centery, GLfloat centerz, GLfloat upx, GLfloat upy, GLfloat upz);

GLint gluProject(GLfloat objx, GLfloat objy, GLfloat objz, const GLfloat modelMatrix[16], const GLfloat projMatrix[16], const GLint viewport[4], GLfloat* winx, GLfloat* winy, GLfloat* winz);

GLint gluUnProject(GLfloat winx, GLfloat winy, GLfloat winz, const GLfloat modelMatrix[16], const GLfloat projMatrix[16], const GLint viewport[4], GLfloat* objx, GLfloat* objy, GLfloat* objz);

void gluPickMatrix(GLfloat x, GLfloat y, GLfloat deltax, GLfloat deltay, GLint viewport[4]);

#endif     