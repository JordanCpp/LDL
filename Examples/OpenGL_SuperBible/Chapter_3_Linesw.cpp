// Linesw.c
// OpenGL SuperBible, Chapter 4
// Demonstrates primative GL_LINES with line widths
// Program by Richard S. Wright Jr. 
// Modifed for LDL framework by Zoshchuk Evgeniy (Jordan)

#include <LDL/LDL.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_2.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Enums;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Math;

// Define a constant for the value of PI
#define GL_PI 3.1415f

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

// Called to draw scene
void RenderScene(void)
{
	GLfloat y;					// Storeage for varying Y coordinate
	GLfloat fSizes[2];			// Line width range metrics
	GLfloat fCurrSize;			// Save current size


	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);

	// Save matrix state and do the rotation
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	// Get line size metrics and save the smallest value
	glGetFloatv(GL_LINE_WIDTH_RANGE, fSizes);
	fCurrSize = fSizes[0];

	// Step up Y axis 20 units at a time	
	for (y = -90.0f; y < 90.0f; y += 20.0f)
	{
		// Set the line width
		glLineWidth(fCurrSize);

		// Draw the line
		glBegin(GL_LINES);
		glVertex2f(-80.0f, y);
		glVertex2f(80.0f, y);
		glEnd();

		// Increase the line width
		fCurrSize += 1.0f;
	}


	// Restore transformations
	glPopMatrix();
}

// This function does any needed initialization on the rendering
// context. 
void SetupRC()
{
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Set drawing color to green
	glColor3f(0.0f, 1.0f, 0.0f);
}

void SpecialKeys(int key)
{
	if (key == KeyboardKey::Up)
		xRot -= 5.0f;

	if (key == KeyboardKey::Down)
		xRot += 5.0f;

	if (key == KeyboardKey::Left)
		yRot -= 5.0f;

	if (key == KeyboardKey::Right)
		yRot += 5.0f;

	if (key > 356.0f)
		xRot = 0.0f;

	if (key < -1.0f)
		xRot = 355.0f;

	if (key > 356.0f)
		yRot = 0.0f;

	if (key < -1.0f)
		yRot = 355.0f;
}


void ChangeSize(int w, int h)
{
	GLfloat nRange = 100.0f;

	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange * h / w, nRange * h / w, -nRange, nRange);
	else
		glOrtho(-nRange * w / h, nRange * w / h, -nRange, nRange, -nRange, nRange);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

///////////////////////////////////////////////////////////
// Main Program Entry Point
int main()
{
	Result result;
	RenderContext renderContext;

	Window window(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), "Line Width Example");
	Render render(result, renderContext, &window);

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

			if (report.Type == IsKeyboard && report.Keyboard.State == ButtonState::Pressed)
			{
				SpecialKeys(report.Keyboard.Key);
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
