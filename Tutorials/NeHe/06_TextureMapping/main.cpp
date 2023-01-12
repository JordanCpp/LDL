#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>
#include <LDL/Graphics/Gpu/GpuWindow.hpp>
#include <LDL/Graphics/Gpu/GpuRender.hpp>
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include <LDL/OpenGL/OpenGL_Matrix4.hpp>
#include <LDL/Allocators/FixedLinear.hpp>

using namespace LDL::Graphics;

const std::string LessonTittle = "Texture Mapping";

GLfloat	xrot;
GLfloat	yrot;
GLfloat	zrot;

GLuint texture[1];

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
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

GLvoid Load(LDL::Loaders::ImageLoader & loader)
{
	loader.Load("NeHe.bmp");

	glGenTextures(1, &texture[0]);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)loader.Size().PosX(), (GLsizei)loader.Size().PosY(), 0, GL_RGB, GL_UNSIGNED_BYTE, loader.Pixels());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

GLvoid Draw()
{		
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();							
	glTranslatef(0.0f, 0.0f, -5.0f);

	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);

	glBindTexture(GL_TEXTURE_2D, texture[0]);

	glBegin(GL_QUADS);
	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	// Back Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	xrot += 0.3f;
	yrot += 0.2f;
	zrot += 0.4f;
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

		LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 2);
		LDL::Loaders::ImageLoader loader(&allocator);

		Init();
		Resize((GLsizei)window.Size().PosX(), (GLsizei)window.Size().PosY());
		Load(loader);

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