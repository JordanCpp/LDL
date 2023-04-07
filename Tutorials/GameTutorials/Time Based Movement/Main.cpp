//***********************************************************************//
//																		 //
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -		 //
//                                                                       //
//		$Author:		DigiBen		DigiBen@GameTutorials.com			 //
//																		 //
//		$Program:		TimeBasedMovement								 //
//																		 //
//		$Description:	Demonstrates camera movement in regards to time	 //

#include <iostream>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Time/Ticks.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Core/RuntimeError.hpp>

#include <LDL/OpenGL/OpenGL1_1.hpp>
#include <LDL/OpenGL/OpenGLUtility.hpp>

#include "Camera.h"

#define SCREEN_WIDTH  800								// We want our screen width 800 pixels
#define SCREEN_HEIGHT 600								// We want our screen height 600 pixels

CCamera g_Camera(SCREEN_WIDTH, SCREEN_HEIGHT);			// This is our global camera object

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Enums;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Time;

///////////////////////////////////////////////////////////////////////////////////////
//
// The code in this tutorial was taken from the Camera5 tutorial.  The point of this
// tutorial is to show how to make time based movement with the camera.  This means
// that the camera speed will be the same, no matter how fast the person's machine
// or video card is.  Granted, that the frames might render faster, but the player
// will not get from point A to B faster than the next guy.  Without doing time
// based movement, and doing just frame based movement, a person with a Geforce2
// will go incredibly faster than a person running a TNT2 in the level.  Some might
// try and lock their frame rate to compensate for this, but this doesn't always work.
// So spots might have more polygons that are being rendered and might make the player
// go slower on those parts, yet faster on low poly parts of the level.  
// 
// This feature is a MUST in any engine.  In the tutorial, we mixed the FPS
// and Camera5 tutorial together.  That way you don't have to sift through some new
// code to pick out the few lines that need to be added to make this feature happen.
// I will only mark these before mentioned lines as NEW so you can pick them out easier.
// Basically, all that's going on is that we are saving the time elapsed between each
// frame, then multiplying that interval by our desired speed.
//
// Notice that we did change the colors of the pyramids, just to give it a new look.
//
//

///////////////////////////////// CREATE PYRAMID \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This creates a pyramid with the center being (X, Y, Z).
/////   The width and height depend on the WIDTH and HEIGHT passed in
/////
///////////////////////////////// CREATE PYRAMID \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void CreatePyramid(float x, float y, float z, int width, int height)
{
	// Start rendering the 4 triangles for the sides
	glBegin(GL_TRIANGLES);		
		
		// These vertices create the Back Side
		glColor3ub(255, 255, 0);   glVertex3f(x, y + height, z);					// Top point
		glColor3ub(255, 255, 255); glVertex3f(x - width, y - height, z - width);	// Bottom left point
		glColor3ub(255, 0, 0); glVertex3f(x + width, y - height, z - width);		// Bottom right point

		// These vertices create the Front Side
		glColor3ub(255, 255, 0);   glVertex3f(x, y + height, z);					// Top point
		glColor3ub(255, 255, 255); glVertex3f(x + width, y - height, z + width);	// Bottom right point
		glColor3ub(255, 0, 0); glVertex3f(x - width, y - height, z + width);		// Bottom left point

		// These vertices create the Front Left Side
		glColor3ub(255, 255, 0);   glVertex3f(x, y + height, z);					// Top point
		glColor3ub(255, 0, 0); glVertex3f(x - width, y - height, z + width);		// Front bottom point
		glColor3ub(255, 255, 255); glVertex3f(x - width, y - height, z - width);	// Bottom back point

		// These vertices create the Front Right Side
		glColor3ub(255, 255, 0);   glVertex3f(x, y + height, z);					// Top point
		glColor3ub(255, 0, 0); glVertex3f(x + width, y - height, z - width);		// Bottom back point
		glColor3ub(255, 255, 255); glVertex3f(x + width, y - height, z + width);	// Front bottom point
			
	glEnd();

	// Now render the bottom of our pyramid

	glBegin(GL_QUADS);

		// These vertices create the bottom of the pyramid
		glColor3ub(0, 0, 255); glVertex3f(x - width, y - height, z + width);	// Front left point
		glColor3ub(0, 0, 255); glVertex3f(x + width, y - height, z + width);    // Front right point
		glColor3ub(0, 0, 255); glVertex3f(x + width, y - height, z - width);    // Back right point
		glColor3ub(0, 0, 255); glVertex3f(x - width, y - height, z - width);    // Back left point
	glEnd();
}


///////////////////////////////// DRAW 3D GRID \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function create a simple grid to get a better view of the animation
/////
///////////////////////////////// DRAW 3D GRID \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void Draw3DSGrid()
{
	// Turn the lines GREEN
	glColor3ub(0, 255, 0);

	// Draw a 1x1 grid along the X and Z axis'
	for(float i = -50; i <= 50; i += 1)
	{
		// Start drawing some lines
		glBegin(GL_LINES);

			// Do the horizontal lines (along the X)
			glVertex3f(-50, 0, i);
			glVertex3f(50, 0, i);

			// Do the vertical lines (along the Z)
			glVertex3f(i, 0, -50);
			glVertex3f(i, 0, 50);

		// Stop drawing lines
		glEnd();
	}
}


///////////////////////////////// DRAW SPIRAL TOWERS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This draws a spiral of pyramids to maneuver around
/////
///////////////////////////////// DRAW SPIRAL TOWERS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void DrawSpiralTowers()
{
	const float PI = 3.14159f;							// Create a constant for PI
	const float kIncrease = PI / 16.0f;					// This is the angle we increase by in radians
	const float kMaxRotation = PI * 6;					// This is 1080 degrees of rotation in radians (3 circles)
	float radius = 40;									// We start with a radius of 40 and decrease towards the center

	// Keep looping until we go past the max degrees of rotation (which is 3 full rotations)
	for(float degree = 0; degree < kMaxRotation; degree += kIncrease)
	{
		// Here we use polar coordinates for the rotations, but we swap the y with the z
		float x = float(radius * cos(degree));			// Get the x position for the current rotation and radius
		float z = float(radius * sin(degree));			// Get the z position for the current rotation and radius

		// Create a pyramid for every degree in our spiral with a width of 1 and height of 3 
		CreatePyramid(x, 3, z, 1, 3);
	
		// Decrease the radius by the constant amount so the pyramids spirals towards the center
		radius -= 40 / (kMaxRotation / kIncrease);
	}	
}

//////////////////////////// RESIZE OPENGL SCREEN \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function resizes the viewport for OpenGL.
/////
//////////////////////////// RESIZE OPENGL SCREEN \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
void SizeOpenGLScreen(int width, int height)			// Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero error
	{
		height = 1;										// Make the Height Equal One
	}

	glViewport(0, 0, width, height);						// Make our viewport the whole window
	// We could make the view smaller inside
	// Our window if we wanted too.
	// The glViewport takes (x, y, width, height)
	// This basically means, what are our drawing boundaries

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	// The parameters are:
	// (view angle, aspect ration of the width to the height, 
	//  the closest distance to the camera before it clips, 
// FOV		// Ratio				//  the farthest distance before it stops drawing).
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 1.0f, 150.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}


///////////////////////////////// RENDER SCENE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function renders the entire scene.
/////
///////////////////////////////// RENDER SCENE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void RenderScene() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glLoadIdentity();									// Reset The matrix

	// Tell OpenGL where to point the camera
	g_Camera.Look();

	// Draw a grid so we can get a good idea of movement around the world		
	Draw3DSGrid();

	// Draw the pyramids that spiral in to the center
	DrawSpiralTowers();
}

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(SCREEN_WIDTH, SCREEN_HEIGHT), "LearnOpenGL");

		RenderContext renderContext;
		Render render(&renderContext, &window);

		Event report;

		FixedLinear allocator(Allocator::Mb * 4);
		ImageLoader loader(&allocator);

		SizeOpenGLScreen((int)window.Size().PosX(), (int)window.Size().PosY());

		g_Camera.PositionCamera(0, 1.5f, 6, 0, 1.5f, 0, 0, 1, 0);

		glEnable(GL_DEPTH_TEST);

		float deltaTime = 0.0f;	// time between current frame and last frame
		float lastFrame = 0.0f;

		while (window.GetEvent(report))
		{
			float currentFrame = static_cast<float>(Ticks() / 1000.0f);
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			//render.Begin();
			
			g_Camera.Update(deltaTime);				// Update the camera every frame
			RenderScene();							// Render the scene every frame

			render.End();

			if (report.IsKeyPresed(KeyboardKey::W))
				g_Camera.MoveCamera(g_Camera.Speed(deltaTime));

			if (report.IsKeyPresed(KeyboardKey::S))
				g_Camera.MoveCamera(-g_Camera.Speed(deltaTime));

			if (report.IsKeyPresed(KeyboardKey::A))
				g_Camera.StrafeCamera(-g_Camera.Speed(deltaTime));

			if (report.IsKeyPresed(KeyboardKey::D))
				g_Camera.StrafeCamera(g_Camera.Speed(deltaTime));

			if (report.Type == IsResize)
			{
				SizeOpenGLScreen((int)report.Resize.Width, (int)report.Resize.Height);
			}

			if (report.Type == IsQuit || report.IsKeyPresed(KeyboardKey::Escape))
			{
				window.StopEvent();
			}
		}
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
// * QUICK NOTES * 
//
// Simple Huh!!!  This is probably one of the simplest tutorials in 3D we have.
// Though it might seem complicated to wrap your head around at first, it's
// only a few extra lines of code to add.  Now you guys have no excuse for frame
// based movement in your demos/games :)
// 
// The basic premise is, calculate the time (in seconds) between each frame,
// then multiply that elapsed time by your speed that you desire.  Try it! 
//
// This tutorial includes a new header file, <mmsystem.h>. This is so we can use
// the timeGetTime() function instead of GetTickCount().  Apparently, GetTickCount()
// doesn't seem to update as fast as timeGetTime().  What you really should use
// is QueryPerformanceCounter() and QueryPerformanceFrequency().  These seem to
// be the fastest method to get time from your CPU.
//
// Enjoy!
// 
//
// © 2000-2005 GameTutorials
//