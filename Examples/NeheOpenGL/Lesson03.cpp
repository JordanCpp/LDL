#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/Convert.hpp>
#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/APIs/OpenGL/OpenGLUtility.hpp>

using namespace LDL::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;

void ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)								    // Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);					// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

int InitGL()										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	return true;										// Initialization Went OK
}

int DrawGLScene()									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix
	glTranslatef(-1.5f, 0.0f, -6.0f);					// Move Left 1.5 Units And Into The Screen 6.0
	glBegin(GL_TRIANGLES);								// Drawing Using Triangles
	glColor3f(1.0f, 0.0f, 0.0f);						// Set The Color To Red
	glVertex3f(0.0f, 1.0f, 0.0f);					    // Top
	glColor3f(0.0f, 1.0f, 0.0f);						// Set The Color To Green
	glVertex3f(-1.0f, -1.0f, 0.0f);					    // Bottom Left
	glColor3f(0.0f, 0.0f, 1.0f);						// Set The Color To Blue
	glVertex3f(1.0f, -1.0f, 0.0f);					    // Bottom Right
	glEnd();											// Finished Drawing The Triangle
	glTranslatef(3.0f, 0.0f, 0.0f);						// Move Right 3 Units
	glColor3f(0.5f, 0.5f, 1.0f);						// Set The Color To Blue One Time Only
	glBegin(GL_QUADS);									// Draw A Quad
	glVertex3f(-1.0f, 1.0f, 0.0f);					    // Top Left
	glVertex3f(1.0f, 1.0f, 0.0f);					    // Top Right
	glVertex3f(1.0f, -1.0f, 0.0f);					    // Bottom Right
	glVertex3f(-1.0f, -1.0f, 0.0f);					    // Bottom Left
	glEnd();											// Done Drawing The Quad

	return true;										// Keep Going
}

int main()
{
		RenderContext renderContext(RenderMode::OpenGL1);

		Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
		Render render(&renderContext, &window);

		Event report;

		FpsCounter fpsCounter;
		Convert convert;
		FpsLimiter fpsLimiter;

		InitGL();

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

			render.Begin();

			ReSizeGLScene((GLsizei)window.Size().x, (GLsizei)window.Size().y);
			DrawGLScene();

			render.End();

			fpsLimiter.Throttle();

			if (fpsCounter.Calc())
			{
				window.Title(convert.ToString(fpsCounter.Fps()));
				fpsCounter.Clear();
			}

			window.PollEvents();
		}

	return 0;
}
