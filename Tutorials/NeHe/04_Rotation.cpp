#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include <LDL/OpenGL/OpenGL_Matrix4.hpp>

using namespace LDL::Graphics;

const std::string LessonTittle = "Adding Color";

GLfloat	rtri = 0;
GLfloat	rquad = 0;

LDL::Matrix4 projection;
LDL::Matrix4 modelView;

GLvoid Resize(GLsizei width, GLsizei height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	projection.Perspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
	glLoadMatrixd(projection.Values());

	glMatrixMode(GL_MODELVIEW);
	modelView.Identity();
	glLoadMatrixd(modelView.Values());
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
	glRotatef(rtri, 0.0f, 1.0f, 0.0f);	

	glBegin(GL_TRIANGLES);					
	glColor3f(1.0f, 0.0f, 0.0f);					
	glVertex3f(0.0f, 1.0f, 0.0f);				
	glColor3f(0.0f, 1.0f, 0.0f);				
	glVertex3f(-1.0f, -1.0f, 0.0f);				
	glColor3f(0.0f, 0.0f, 1.0f);				
	glVertex3f(1.0f, -1.0f, 0.0f);					
	glEnd();	

	glLoadIdentity();		

	glTranslatef(1.5f, 0.0f, -6.0f);					
	glRotatef(rquad, 1.0f, 0.0f, 0.0f);			
	glColor3f(0.5f, 0.5f, 1.0f);	

	glBegin(GL_QUADS);								
	glVertex3f(-1.0f, 1.0f, 0.0f);					
	glVertex3f(1.0f, 1.0f, 0.0f);				
	glVertex3f(1.0f, -1.0f, 0.0f);					
	glVertex3f(-1.0f, -1.0f, 0.0f);					
	glEnd();									

	rtri += 0.2f;											
	rquad -= 0.15f;
}

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(800, 600), LessonTittle);

		Render render(&window);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;

		Init();

		while (window.GetEvent(report))
		{
			fpsCounter.Start();

			render.Begin();

			Resize((GLsizei)window.Size().PosX(), (GLsizei)window.Size().PosY());
			Draw();

			render.End();

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
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