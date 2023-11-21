#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/OpenGL/OpenGLUtility.hpp>

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace LDL::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;

bool blend = false;				// Blending ON/OFF
bool bp    = false;				// B Pressed?
bool fp    = false;				// F Pressed?

const float piover180 = 0.0174532925f;

float heading = 0.0f;
float xpos    = 0.0f;
float zpos    = 0.0f;

GLfloat	yrot          = 0.0f;			// Y Rotation
GLfloat walkbias      = 0.0f;
GLfloat walkbiasangle = 0.0f;
GLfloat lookupdown    = 0.0f;
GLfloat	z             = 0.0f;			// Depth Into The Screen

GLuint	filter = 0;				// Which Filter To Use
GLuint	texture[3];			// Storage For 3 Textures

struct VERTEX
{
	float x, y, z;
	float u, v;
};

struct TRIANGLE
{
	VERTEX vertex[3];
};

struct SECTOR
{
	int numtriangles;
	TRIANGLE* triangle;
};

SECTOR sector1;				// Our Model Goes Here:

void readstr(FILE* f, char* string)
{
	do
	{
		fgets(string, 255, f);
	} while ((string[0] == '/') || (string[0] == '\n'));
	return;
}

void SetupWorld()
{
	float x, y, z, u, v;
	int numtriangles;
	FILE* filein;
	char oneline[255];
	filein = fopen("data/world.txt", "rt");				// File To Load World Data From

	readstr(filein, oneline);
	sscanf(oneline, "NUMPOLLIES %d\n", &numtriangles);

	sector1.triangle = (TRIANGLE*)malloc(sizeof(TRIANGLE) * numtriangles);
	//	sector1.triangle = new TRIANGLE[numtriangles];
	sector1.numtriangles = numtriangles;

	for (int loop = 0; loop < numtriangles; loop++)
	{
		for (int vert = 0; vert < 3; vert++)
		{
			readstr(filein, oneline);
			sscanf(oneline, "%f %f %f %f %f", &x, &y, &z, &u, &v);
			sector1.triangle[loop].vertex[vert].x = x;
			sector1.triangle[loop].vertex[vert].y = y;
			sector1.triangle[loop].vertex[vert].z = z;
			sector1.triangle[loop].vertex[vert].u = u;
			sector1.triangle[loop].vertex[vert].v = v;
		}
	}

	fclose(filein);
	return;
}

void LoadGLTextures(ImageLoader& loader)
{
	loader.Load("Data/Mud.bmp");


	glGenTextures(3, &texture[0]);          // Create Three Textures

	// Create Nearest Filtered Texture
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)loader.Size().x, (GLsizei)loader.Size().y, 0, GL_RGB, GL_UNSIGNED_BYTE, loader.Pixels());

	// Create Linear Filtered Texture
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)loader.Size().x, (GLsizei)loader.Size().y, 0, GL_RGB, GL_UNSIGNED_BYTE, loader.Pixels());

	// Create MipMapped Texture
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, (GLsizei)loader.Size().x, (GLsizei)loader.Size().y, GL_RGB, GL_UNSIGNED_BYTE, loader.Pixels());
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
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);					// Set The Blending Function For Translucency
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// This Will Clear The Background Color To Black
	glClearDepth(1.0);									// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS);								// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glShadeModel(GL_SMOOTH);							// Enables Smooth Color Shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	SetupWorld();

	return true;										// Initialization Went OK
}

int DrawGLScene()									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glLoadIdentity();									// Reset The View

	GLfloat x_m, y_m, z_m, u_m, v_m;
	GLfloat xtrans = -xpos;
	GLfloat ztrans = -zpos;
	GLfloat ytrans = -walkbias - 0.25f;
	GLfloat sceneroty = 360.0f - yrot;

	int numtriangles;

	glRotatef(lookupdown, 1.0f, 0, 0);
	glRotatef(sceneroty, 0, 1.0f, 0);

	glTranslatef(xtrans, ytrans, ztrans);
	glBindTexture(GL_TEXTURE_2D, texture[filter]);

	numtriangles = sector1.numtriangles;

	// Process Each Triangle
	for (int loop_m = 0; loop_m < numtriangles; loop_m++)
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(0.0f, 0.0f, 1.0f);
		x_m = sector1.triangle[loop_m].vertex[0].x;
		y_m = sector1.triangle[loop_m].vertex[0].y;
		z_m = sector1.triangle[loop_m].vertex[0].z;
		u_m = sector1.triangle[loop_m].vertex[0].u;
		v_m = sector1.triangle[loop_m].vertex[0].v;
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);

		x_m = sector1.triangle[loop_m].vertex[1].x;
		y_m = sector1.triangle[loop_m].vertex[1].y;
		z_m = sector1.triangle[loop_m].vertex[1].z;
		u_m = sector1.triangle[loop_m].vertex[1].u;
		v_m = sector1.triangle[loop_m].vertex[1].v;
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);

		x_m = sector1.triangle[loop_m].vertex[2].x;
		y_m = sector1.triangle[loop_m].vertex[2].y;
		z_m = sector1.triangle[loop_m].vertex[2].z;
		u_m = sector1.triangle[loop_m].vertex[2].u;
		v_m = sector1.triangle[loop_m].vertex[2].v;
		glTexCoord2f(u_m, v_m); glVertex3f(x_m, y_m, z_m);
		glEnd();
	}

	return true;										// Everything Went OK
}

int main()
{
	try
	{
		RenderContext renderContext(RenderMode::OpenGL1);

		Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
		Render render(&renderContext, &window);

	    FixedLinear allocator(Allocator::Mb * 2);
		ImageLoader loader(&allocator);

		Event report;

		FpsCounter fpsCounter;
		NumberToString convert;

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

				if (report.IsKeyPressed(KeyboardKey::B) && !bp)
				{
					bp = true;
					blend = !blend;
					if (!blend)
					{
						glDisable(GL_BLEND);
						glEnable(GL_DEPTH_TEST);
					}
					else
					{
						glEnable(GL_BLEND);
						glDisable(GL_DEPTH_TEST);
					}
				}
				if (!report.IsKeyPressed(KeyboardKey::B))
				{
					bp = false;
				}

				if (report.IsKeyPressed(KeyboardKey::F) && !fp)
				{
					fp = true;
					filter += 1;
					if (filter > 2)
					{
						filter = 0;
					}
				}
				if (!report.IsKeyPressed(KeyboardKey::F))
				{
					fp = false;
				}

				if (report.IsKeyPressed(KeyboardKey::PageUp))
				{
					z -= 0.02f;
				}

				if (report.IsKeyPressed(KeyboardKey::PageDown))
				{
					z += 0.02f;
				}

				if (report.IsKeyPressed(KeyboardKey::Up))
				{

					xpos -= (float)sin(heading * piover180) * 0.05f;
					zpos -= (float)cos(heading * piover180) * 0.05f;
					if (walkbiasangle >= 359.0f)
					{
						walkbiasangle = 0.0f;
					}
					else
					{
						walkbiasangle += 10;
					}
					walkbias = (float)sin(walkbiasangle * piover180) / 20.0f;
				}

				if (report.IsKeyPressed(KeyboardKey::Down))
				{
					xpos += (float)sin(heading * piover180) * 0.05f;
					zpos += (float)cos(heading * piover180) * 0.05f;
					if (walkbiasangle <= 1.0f)
					{
						walkbiasangle = 359.0f;
					}
					else
					{
						walkbiasangle -= 10;
					}
					walkbias = (float)sin(walkbiasangle * piover180) / 20.0f;
				}

				if (report.IsKeyPressed(KeyboardKey::Right))
				{
					heading -= 1.0f;
					yrot = heading;
				}

				if (report.IsKeyPressed(KeyboardKey::Left))
				{
					heading += 1.0f;
					yrot = heading;
				}

				if (report.IsKeyPressed(KeyboardKey::PageUp))
				{
					lookupdown -= 1.0f;
				}

				if (report.IsKeyPressed(KeyboardKey::PageDown))
				{
					lookupdown += 1.0f;
				}
			}

			render.Begin();

			ReSizeGLScene((GLsizei)window.Size().x, (GLsizei)window.Size().y);
			DrawGLScene();

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
