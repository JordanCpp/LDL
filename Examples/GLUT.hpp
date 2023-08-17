#ifndef LDL_Examples_OpenGL1_GLUT_hpp
#define LDL_Examples_OpenGL1_GLUT_hpp

#include <LDL/OpenGL/OpenGL1_2.hpp>

namespace GLUT
{
	const double Pi = 3.14159265358979323846;

	void doughnut(GLfloat r, GLfloat R, GLint nsides, GLint rings)
	{
		int i, j;
		GLfloat theta, phi, theta1;
		GLfloat cosTheta, sinTheta;
		GLfloat cosTheta1, sinTheta1;
		GLfloat ringDelta, sideDelta;

		ringDelta = float(2.0 * Pi / rings);
		sideDelta = float(2.0 * Pi / nsides);

		theta = 0.0;
		cosTheta = 1.0;
		sinTheta = 0.0;
		for (i = rings - 1; i >= 0; i--) {
			theta1 = theta + ringDelta;
			cosTheta1 = cos(theta1);
			sinTheta1 = sin(theta1);
			glBegin(GL_QUAD_STRIP);
			phi = 0.0;
			for (j = nsides; j >= 0; j--) {
				GLfloat cosPhi, sinPhi, dist;

				phi += sideDelta;
				cosPhi = cos(phi);
				sinPhi = sin(phi);
				dist = R + r * cosPhi;

				glNormal3f(cosTheta1 * cosPhi, -sinTheta1 * cosPhi, sinPhi);
				glVertex3f(cosTheta1 * dist, -sinTheta1 * dist, r * sinPhi);
				glNormal3f(cosTheta * cosPhi, -sinTheta * cosPhi, sinPhi);
				glVertex3f(cosTheta * dist, -sinTheta * dist, r * sinPhi);
			}
			glEnd();
			theta = theta1;
			cosTheta = cosTheta1;
			sinTheta = sinTheta1;
		}
	}

	void glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings)
	{
		glPushAttrib(GL_POLYGON_BIT);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		doughnut((float)innerRadius, (float)outerRadius, nsides, rings);
		glPopAttrib();
	}
}

#endif 