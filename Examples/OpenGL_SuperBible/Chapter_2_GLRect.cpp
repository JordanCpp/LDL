// GLRect.c
// Just draw a single rectangle in the middle of the screen
// OpenGL SuperBible, 3rd Edition
// Richard S. Wright Jr.
// rwright@starstonesoftware.com  
// Modifed for LDL framework by Zoshchuk Evgeniy (Jordan)

#include <LDL/LDL.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_2.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Math;

///////////////////////////////////////////////////////////
// Called to draw scene
void RenderScene(void)
{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);

	// Set current drawing color to red
	//		   R	 G	   B
	glColor3f(1.0f, 0.0f, 0.0f);

	// Draw a filled rectangle with current color
	glRectf(-25.0f, 25.0f, 25.0f, -25.0f);
}

///////////////////////////////////////////////////////////
// Setup the rendering state
void SetupRC(void)
{
	// Set clear color to blue
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

///////////////////////////////////////////////////////////
// Called by GLUT library when the window has chanaged size
void ChangeSize(int w, int h)
{
	GLfloat aspectRatio;

	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)
		glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else
		glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

///////////////////////////////////////////////////////////
// Main program entry point  
int main()
{
	RenderContext renderContext;

	Window window(renderContext, Vec2u(0, 0), Vec2u(800, 600), "GLRect");
	Render render(renderContext, &window);

	Event report;

	FpsCounter fpsCounter;
	Convert convert;

	SetupRC();

	while (window.Running())
	{
		fpsCounter.Start();

		while (window.GetEvent(report))
		{
			if (report.Type == IsQuit)
			{
				window.StopEvent();
			}
		}

		render.Begin();

		ChangeSize((int)window.Size().x, (int)window.Size().y);

		RenderScene();

		render.End();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));
			fpsCounter.Clear();
		}

		window.PollEvents();
	}

	return 0;
}
