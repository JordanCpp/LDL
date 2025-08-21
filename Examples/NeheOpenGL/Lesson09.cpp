#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/Convert.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/APIs/OpenGL/OpenGLUtility.hpp>
#include <stdlib.h>

using namespace LDL::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;

bool twinkle = false;			// Twinkling Stars
bool tp      = false;			// 'T' Key Pressed?

const int num = 50;		// Number Of Stars To Draw

struct stars				// Create A Structure For Star
{
	int r, g, b;			// Stars Color
	GLfloat dist;			// Stars Distance From Center
	GLfloat	angle;			// Stars Current Angle
};

stars star[num];			// Need To Keep Track Of 'num' Stars

GLfloat	zoom = -15.0f;		// Distance Away From Stars
GLfloat tilt = 90.0f;		// Tilt The View
GLfloat	spin;				// Spin Stars

GLuint	loop;				// General loop Variable
GLuint	texture[1];			// Storage For One textures

void LoadGLTextures(ImageLoader& loader)
{
	loader.Load("Data/Star.bmp");

	glGenTextures(1, &texture[0]);					// Create Three Textures

	// Create Linear Filtered Texture
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)loader.Size().x, (GLsizei)loader.Size().y, 0, GL_RGB, GL_UNSIGNED_BYTE, loader.Pixels());
}

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
	glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);					// Set The Blending Function For Translucency
	glEnable(GL_BLEND);

	for (loop = 0; loop < num; loop++)
	{
		star[loop].angle = 0.0f;
		star[loop].dist = ((float)loop / num) * 5.0f;
		star[loop].r = rand() % 256;
		star[loop].g = rand() % 256;
		star[loop].b = rand() % 256;
	}

	return true;										// Initialization Went OK
}

int DrawGLScene()									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glBindTexture(GL_TEXTURE_2D, texture[0]);			// Select Our Texture

	for (loop = 0; loop < num; loop++)					// loop Through All The Stars
	{
		glLoadIdentity();								// Reset The View Before We Draw Each Star
		glTranslatef(0.0f, 0.0f, zoom);					// Zoom Into The Screen (Using The Value In 'zoom')
		glRotatef(tilt, 1.0f, 0.0f, 0.0f);				// Tilt The View (Using The Value In 'tilt')
		glRotatef(star[loop].angle, 0.0f, 1.0f, 0.0f);	// Rotate To The Current Stars Angle
		glTranslatef(star[loop].dist, 0.0f, 0.0f);		// Move Forward On The X Plane
		glRotatef(-star[loop].angle, 0.0f, 1.0f, 0.0f);	// Cancel The Current Stars Angle
		glRotatef(-tilt, 1.0f, 0.0f, 0.0f);				// Cancel The Screen Tilt

		if (twinkle)
		{
			glColor4ub(star[(num - loop) - 1].r, star[(num - loop) - 1].g, star[(num - loop) - 1].b, 255);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
			glEnd();
		}

		glRotatef(spin, 0.0f, 0.0f, 1.0f);
		glColor4ub(star[loop].r, star[loop].g, star[loop].b, 255);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();

		spin += 0.01f;
		star[loop].angle += (float)loop / num;
		star[loop].dist -= 0.01f;
		if (star[loop].dist < 0.0f)
		{
			star[loop].dist += 5.0f;
			star[loop].r = rand() % 256;
			star[loop].g = rand() % 256;
			star[loop].b = rand() % 256;
		}
	}

	return true;										// Everything Went OK
}

int main()
{
		RenderContext renderContext(RenderMode::OpenGL1);

		Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
		Render render(&renderContext, &window);

	    FixedLinear allocator(Allocator::Mb * 2);
		ImageLoader loader(&allocator);

		Event report;

		FpsCounter fpsCounter;
		Convert convert;

		InitGL();
		LoadGLTextures(loader);

		while (window.Running())
		{
			fpsCounter.Start();

			while (window.GetEvent(report))
			{
				if (report.Type == IsQuit)
				{
					window.StopEvent();
				}

				if (report.IsKeyPressed(KeyboardKey::Escape))
					window.StopEvent();

				if (report.IsKeyPressed(KeyboardKey::T) && !tp)
				{
					tp      = true;
					twinkle = !twinkle;
				}

				if (!report.IsKeyPressed(KeyboardKey::T))
				{
					tp = false;
				}

				if (report.IsKeyPressed(KeyboardKey::Up))
				{
					tilt -= 0.5f;
				}

				if (report.IsKeyPressed(KeyboardKey::Down))
				{
					tilt += 0.5f;
				}

				if (report.IsKeyPressed(KeyboardKey::PageUp))
				{
					zoom -= 0.2f;
				}

				if (report.IsKeyPressed(KeyboardKey::PageDown))
				{
					zoom += 0.2f;
				}
			}

			render.Begin();

			ReSizeGLScene((GLsizei)window.Size().x, (GLsizei)window.Size().y);
			DrawGLScene();

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
