#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include <LDL/Math/Funcs.hpp>
#include <LDL/Math/Mat4f.hpp>
#include <LDL/Math/Vec3f.hpp>
#include <LDL/Time/FpsLimiter.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

const std::string LessonTittle = "Lesson 05 - 3D Shapes";

GLfloat	rtri = 0;
GLfloat	rquad = 0;

Mat4f projection;
Mat4f modelView;

GLvoid Resize(GLsizei width, GLsizei height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	projection = Perspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
	glLoadMatrixf(projection.Values());

	glMatrixMode(GL_MODELVIEW);
	modelView.Identity();
	glLoadMatrixf(modelView.Values());
}

GLvoid Init()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

GLvoid Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer

	modelView.Identity();
	modelView = Translate(modelView, Vec3f(-1.5f, 0.0f, -6.0f));
	modelView = Rotate(modelView, rtri, Vec3f(0.0f, 1.0f, 0.0f));
	glLoadMatrixf(modelView.Values());

	glBegin(GL_TRIANGLES);								// Start Drawing A Triangle
	glColor3f(1.0f, 0.0f, 0.0f);						// Red
	glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of Triangle (Front)
	glColor3f(0.0f, 1.0f, 0.0f);						// Green
	glVertex3f(-1.0f, -1.0f, 1.0f);					// Left Of Triangle (Front)
	glColor3f(0.0f, 0.0f, 1.0f);						// Blue
	glVertex3f(1.0f, -1.0f, 1.0f);					// Right Of Triangle (Front)
	glColor3f(1.0f, 0.0f, 0.0f);						// Red
	glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of Triangle (Right)
	glColor3f(0.0f, 0.0f, 1.0f);						// Blue
	glVertex3f(1.0f, -1.0f, 1.0f);					// Left Of Triangle (Right)
	glColor3f(0.0f, 1.0f, 0.0f);						// Green
	glVertex3f(1.0f, -1.0f, -1.0f);					// Right Of Triangle (Right)
	glColor3f(1.0f, 0.0f, 0.0f);						// Red
	glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of Triangle (Back)
	glColor3f(0.0f, 1.0f, 0.0f);						// Green
	glVertex3f(1.0f, -1.0f, -1.0f);					// Left Of Triangle (Back)
	glColor3f(0.0f, 0.0f, 1.0f);						// Blue
	glVertex3f(-1.0f, -1.0f, -1.0f);					// Right Of Triangle (Back)
	glColor3f(1.0f, 0.0f, 0.0f);						// Red
	glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of Triangle (Left)
	glColor3f(0.0f, 0.0f, 1.0f);						// Blue
	glVertex3f(-1.0f, -1.0f, -1.0f);					// Left Of Triangle (Left)
	glColor3f(0.0f, 1.0f, 0.0f);						// Green
	glVertex3f(-1.0f, -1.0f, 1.0f);					// Right Of Triangle (Left)
	glEnd();											// Done Drawing The Pyramid

	modelView.Identity();
	modelView = Translate(modelView, Vec3f(1.5f, 0.0f, -7.0f));
	modelView = Rotate(modelView, rtri, Vec3f(1.0f, 1.0f, 1.0f));
	glLoadMatrixf(modelView.Values());

	glBegin(GL_QUADS);									// Draw A Quad
	glColor3f(0.0f, 1.0f, 0.0f);						// Set The Color To Blue
	glVertex3f(1.0f, 1.0f, -1.0f);					// Top Right Of The Quad (Top)
	glVertex3f(-1.0f, 1.0f, -1.0f);					// Top Left Of The Quad (Top)
	glVertex3f(-1.0f, 1.0f, 1.0f);					// Bottom Left Of The Quad (Top)
	glVertex3f(1.0f, 1.0f, 1.0f);					// Bottom Right Of The Quad (Top)
	glColor3f(1.0f, 0.5f, 0.0f);						// Set The Color To Orange
	glVertex3f(1.0f, -1.0f, 1.0f);					// Top Right Of The Quad (Bottom)
	glVertex3f(-1.0f, -1.0f, 1.0f);					// Top Left Of The Quad (Bottom)
	glVertex3f(-1.0f, -1.0f, -1.0f);					// Bottom Left Of The Quad (Bottom)
	glVertex3f(1.0f, -1.0f, -1.0f);					// Bottom Right Of The Quad (Bottom)
	glColor3f(1.0f, 0.0f, 0.0f);						// Set The Color To Red
	glVertex3f(1.0f, 1.0f, 1.0f);					// Top Right Of The Quad (Front)
	glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Left Of The Quad (Front)
	glVertex3f(-1.0f, -1.0f, 1.0f);					// Bottom Left Of The Quad (Front)
	glVertex3f(1.0f, -1.0f, 1.0f);					// Bottom Right Of The Quad (Front)
	glColor3f(1.0f, 1.0f, 0.0f);						// Set The Color To Yellow
	glVertex3f(1.0f, -1.0f, -1.0f);					// Top Right Of The Quad (Back)
	glVertex3f(-1.0f, -1.0f, -1.0f);					// Top Left Of The Quad (Back)
	glVertex3f(-1.0f, 1.0f, -1.0f);					// Bottom Left Of The Quad (Back)
	glVertex3f(1.0f, 1.0f, -1.0f);					// Bottom Right Of The Quad (Back)
	glColor3f(0.0f, 0.0f, 1.0f);						// Set The Color To Blue
	glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Right Of The Quad (Left)
	glVertex3f(-1.0f, 1.0f, -1.0f);					// Top Left Of The Quad (Left)
	glVertex3f(-1.0f, -1.0f, -1.0f);					// Bottom Left Of The Quad (Left)
	glVertex3f(-1.0f, -1.0f, 1.0f);					// Bottom Right Of The Quad (Left)
	glColor3f(1.0f, 0.0f, 1.0f);						// Set The Color To Violet
	glVertex3f(1.0f, 1.0f, -1.0f);					// Top Right Of The Quad (Right)
	glVertex3f(1.0f, 1.0f, 1.0f);					// Top Left Of The Quad (Right)
	glVertex3f(1.0f, -1.0f, 1.0f);					// Bottom Left Of The Quad (Right)
	glVertex3f(1.0f, -1.0f, -1.0f);					// Bottom Right Of The Quad (Right)
	glEnd();											// Done Drawing The Quad

	rtri += 0.2f;											// Increase The Rotation Variable For The Triangle ( NEW )
	rquad -= 0.15f;									
}

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(800, 600), LessonTittle);

		RenderContext renderContext;
		Render render(&renderContext, &window);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::NumberToString convert;
		LDL::Time::FpsLimiter fpsLimiter;
		std::string title;

		Init();

		while (window.GetEvent(report))
		{
			fpsLimiter.Mark();

			fpsCounter.Start();

			render.Begin();

			Resize((GLsizei)window.Size().PosX(), (GLsizei)window.Size().PosY());
			Draw();

			render.End();

			fpsLimiter.Throttle();

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
			}

			if (fpsCounter.Calc())
			{
				title = LessonTittle + " Fps: " + convert.Convert(fpsCounter.Fps());
				window.Title(title);
				fpsCounter.Clear();
			}
		}
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}