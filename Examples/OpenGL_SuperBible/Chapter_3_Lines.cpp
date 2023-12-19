// Lines.c
// Demonstrates primative GL_LINES
// OpenGL SuperBible, 3rd Edition
// Richard S. Wright Jr.
// rwright@starstonesoftware.com  
// Modifed for LDL framework by Zoshchuk Evgeniy (Jordan)

#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Enums/ButtonState.hpp>
#include <LDL/Enums/KeyboardKey.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_2.hpp>
#include <math.h>

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

///////////////////////////////////////////////////////////
// Called to draw scene
void RenderScene(void)
{
	GLfloat x, y, z, angle; // Storeage for coordinates and angles

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);

	// Save matrix state and do the rotation
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	// Call only once for all remaining points
	glBegin(GL_LINES);

	z = 0.0f;
	for (angle = 0.0f; angle <= GL_PI; angle += (GL_PI / 20.0f))
	{
		// Top half of the circle
		x = 50.0f * sin(angle);
		y = 50.0f * cos(angle);
		glVertex3f(x, y, z);

		// Bottom half of the circle
		x = 50.0f * sin(angle + GL_PI);
		y = 50.0f * cos(angle + GL_PI);
		glVertex3f(x, y, z);
	}

	// Done drawing points
	glEnd();

	// Restore transformations
	glPopMatrix();
}

///////////////////////////////////////////////////////////
// This function does any needed initialization on the 
// rendering context. 
void SetupRC()
{
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Set drawing color to green
	glColor3f(0.0f, 1.0f, 0.0f);
}

///////////////////////////////////////////////////////////
// Respond to arrow keys
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

///////////////////////////////////////////////////////////
// Window has changed size, recalculate projection
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
	try
	{
		RenderContext renderContext;

		Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "Lines Example");
		Render render(&renderContext, &window);

		Event report;

		FpsCounter fpsCounter;
		NumberToString convert;

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