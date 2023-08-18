#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/OpenGL/OpenGL1_2.hpp>
#include <LDL/OpenGL/OpenGLUtility.hpp>

using namespace LDL::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;

void Identity()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// A simple three-dimensional point class to make life easy.  It allows you
// to reference points with x and y coordinates instead of array indices) and
// encapsulates a midpoint function.
struct Point {
	GLfloat x, y, z;
	Point(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) {}
	Point midpoint(Point p) { return Point((x + p.x) / 2, (y + p.y) / 2, (z + p.z) / 2); }
};

// Handles reshape requests by setting the the viewport to exactly match the
// pixel coordinates, so we can draw in the whole window.  Then sets up a
// simple perspective viewing volume to ensure that the pyramid will never
// be distorted when the window is reshaped.  The particular settings chosen
// ensure that the vertical extent of the pyramid will always be visible.
void reshape(GLint w, GLint h) 
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0, GLfloat(w) / GLfloat(h), 10.0, 1500.0);
}

// Handles display requests.  All it has to do is clear the viewport because
// the real drawing is done in the idle callback.
void Display() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

// Draws the "next 500 points".  The function contains locally the definitions
// of the vertices and the current point as static objects so that their values
// are retained between calls.
void generateMorePoints() {

	// The tetrahedron has four vertices.  We also have to keep track of the
	// current point during the plotting.
	static Point vertices[4] = {
	  Point(-250, -225, -200),
	  Point(-150, -225, -700),
	  Point(250, -225, -275),
	  Point(0, 450, -500)
	};
	static Point lastPoint = vertices[0];

	// Here is the code to draw the "next 500 points".  The closer the point is
	// to the camera, the brighter we make it.  The coloring technique is a
	// quick hack which (unprofessionally) depends on the fact that the range
	// of z-coordinates in the tetrahedron run from -200 to -700.  By adding
	// 700 to any z-value and then dividing by 500, we get values in the range
	// 0 to 1 - just perfect for coloring.
	glBegin(GL_POINTS);

	for (int i = 0; i <= 500; i++) 
	{
		lastPoint = lastPoint.midpoint(vertices[rand() % 4]);
		GLfloat intensity = (700 + lastPoint.z) / 500.0f;
		glColor3f(intensity, intensity, 0.25);
		glVertex3f(lastPoint.x, lastPoint.y, lastPoint.z);
	}

	glEnd();
}

// Performs application-specific initialization.  In this program we want to
// do depth buffering, which has to be explicitly enabled in OpenGL.
void Init() 
{
	glEnable(GL_DEPTH_TEST);
}

int main()
{
	try
	{
		RenderContext renderContext(RenderMode::OpenGL1);

		Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
		Render render(&renderContext, &window);

		Event report;

		FpsCounter fpsCounter;
		NumberToString convert;
		FpsLimiter fpsLimiter;

		while (window.Running())
		{
			fpsLimiter.Mark();
			fpsCounter.Start();

			while (window.GetEvent(report))
			{
				if (report.Type == IsQuit)
				{
					window.StopEvent();
				}

				if (report.IsKeyPressed(KeyboardKey::Escape))
					window.StopEvent();
			}

			Init();

			render.Begin();
			Display();
			reshape((GLsizei)window.Size().x, (GLsizei)window.Size().y);
			generateMorePoints();

			render.End();

			fpsLimiter.Throttle();

			if (fpsCounter.Calc())
			{
				window.Title(convert.Convert(fpsCounter.Fps()));
				fpsCounter.Clear();
			}

			window.PollEvents();
		}
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}
