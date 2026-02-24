// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/LDL.hpp>
#include <LDL/APIs/OpenGL/GLU.hpp>

using namespace LDL;

bool light = false;			// Lighting ON/OFF ( NEW )
bool blend = false;			// Blending OFF/ON? ( NEW )
bool lp    = false;			// L Pressed? ( NEW )
bool fp    = false;			// F Pressed? ( NEW )
bool bp    = false;			// B Pressed? ( NEW )

GLfloat	xrot   = 0.0;			// X Rotation
GLfloat	yrot   = 0.0;			// Y Rotation
GLfloat xspeed = 0.0;			// X Rotation Speed
GLfloat yspeed = 0.0;			// Y Rotation Speed
GLfloat	z      = -5.0f;			// Depth Into The Screen

GLfloat LightAmbient[]  = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightDiffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[] = { 0.0f, 0.0f, 2.0f, 1.0f };

GLuint	filter = 0;			// Which Filter To Use
GLuint	texture[3];			// Storage For 3 Textures

void LoadGLTextures(ImageLoader& loader)
{
	loader.Load("Data/Glass.bmp");

	glGenTextures(3, &texture[0]);					// Create Three Textures

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
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);		// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);		// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);	// Position The Light
	glEnable(GL_LIGHT1);								// Enable Light One

	return true;										// Initialization Went OK
}

int DrawGLScene()									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glLoadIdentity();									// Reset The View
	glTranslatef(0.0f, 0.0f, z);

	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);

	glBindTexture(GL_TEXTURE_2D, texture[filter]);

	glBegin(GL_QUADS);
	// Front Face
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	// Back Face
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	// Top Face
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	// Bottom Face
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	// Right face
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	// Left Face
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	xrot += xspeed;
	yrot += yspeed;

	return true;										// Keep Going
}

int main()
{
	Result result;
		RenderContext renderContext(RenderMode::OpenGL1);

		Window window(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
		Render render(result, renderContext, &window);

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
				if (report.Type == Event::IsQuit)
				{
					window.StopEvent();
				}

				if (report.IsKeyPressed(KeyboardKey::Escape))
					window.StopEvent();

				if (report.IsKeyPressed(KeyboardKey::Up))
					xspeed -= 0.01f;

				if (report.IsKeyPressed(KeyboardKey::Down))
					xspeed += 0.01f;

				if (report.IsKeyPressed(KeyboardKey::Left))
					yspeed -= 0.01f;

				if (report.IsKeyPressed(KeyboardKey::Right))
					yspeed += 0.01f;

				if (report.IsKeyPressed(KeyboardKey::L) && !lp)
				{
					lp    = true;
					light = !light;

					if (!light)
						glDisable(GL_LIGHTING);
					else
						glEnable(GL_LIGHTING);
				}

				if (!report.IsKeyPressed(KeyboardKey::L))
					lp = false;

				if (report.IsKeyPressed(KeyboardKey::F) && !fp)
				{
					fp      = true;
					filter += 1;

					if (filter > 2)
						filter = 0;
				}

				if (!report.IsKeyPressed(KeyboardKey::F))
					fp = false;

				// Blending Code Starts Here

				if (report.IsKeyPressed(KeyboardKey::B) && !bp)
				{
					bp    = true;
					blend = !blend;

					if (blend)
					{
						glEnable(GL_BLEND);			// Turn Blending On
						glDisable(GL_DEPTH_TEST);	// Turn Depth Testing Off
					}
					else
					{
						glDisable(GL_BLEND);		// Turn Blending Off
						glEnable(GL_DEPTH_TEST);	// Turn Depth Testing On
					}
				}

				if (!report.IsKeyPressed(KeyboardKey::B))
				{
					bp = false;
				}

				// Blending Code Ends Here
			}

			render.Begin();

			ReSizeGLScene((GLsizei)window.Size().x, (GLsizei)window.Size().y);
			DrawGLScene();

			render.End();

			if (fpsCounter.Calc())
			{
				window.Title(convert.ToString(fpsCounter.Fps()));
				
			}

			
		}

	return 0;
}
