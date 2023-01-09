#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>
#include <LDL/Graphics/Gpu/GpuWindow.hpp>
#include <LDL/Graphics/Gpu/GpuRender.hpp>
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include <LDL/OpenGL/OpenGL_Matrix4.hpp>

using namespace LDL::Graphics;

const std::string LessonTittle = "Adding Color";

GLvoid Resize(GLsizei width, GLsizei height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	LDL::Matrix4 projection;
	projection.Perspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
	glLoadMatrixd(projection.Values());

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(-1.5f, 0.0f, -6.0f);

	glBegin(GL_TRIANGLES);							
	glColor3f(1.0f, 0.0f, 0.0f);					
	glVertex3f(0.0f, 1.0f, 0.0f);				
	glColor3f(0.0f, 1.0f, 0.0f);				
	glVertex3f(-1.0f, -1.0f, 0.0f);				
	glColor3f(0.0f, 0.0f, 1.0f);				
	glVertex3f(1.0f, -1.0f, 0.0f);				
	glEnd();	

	glTranslatef(3.0f, 0.0f, 0.0f);		

	glColor3f(0.5f, 0.5f, 1.0f);

	glBegin(GL_QUADS);								
	glVertex3f(-1.0f, 1.0f, 0.0f);					
	glVertex3f(1.0f, 1.0f, 0.0f);					
	glVertex3f(1.0f, -1.0f, 0.0f);				
	glVertex3f(-1.0f, -1.0f, 0.0f);				
	glEnd();
}

int main()
{
	try
	{
		GpuWindow window(Point2u(0, 0), Point2u(800, 600), LessonTittle);

		GpuRender render(&window);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;

		Init();
		Resize((GLsizei)window.Size().PosX(), (GLsizei)window.Size().PosY());

		while (window.GetEvent(report))
		{
			fpsCounter.Start();

			render.Begin();

			Draw();

			render.End();

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
			}

			if (report.Type == LDL::Events::IsResize)
			{
				Resize((GLsizei)report.Resize.Width, (GLsizei)report.Resize.Height);
			}

			if (fpsCounter.Calc())
			{
				window.Title(convert.Convert(fpsCounter.Fps()));
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