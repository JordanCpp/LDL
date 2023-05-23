#include <iostream>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/Ticks.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/OpenGL/OpenGL1_1.hpp>
#include <LDL/Math/Funcs.hpp>
#include <LDL/Math/Mat4f.hpp>
#include <LDL/Math/Vec3f.hpp>

#include "learnopengl/texture.h"

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Enums;
using namespace LDL::Core;
using namespace LDL::Math;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Time;

// settings
const unsigned int SCR_WIDTH  = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(SCR_WIDTH, SCR_HEIGHT), "LearnOpenGL");

		RenderContext renderContext;
		Render render(&renderContext, &window);

		FixedLinear allocator(Allocator::Mb * 4);
		ImageLoader loader(&allocator);

		Event report;

		// set up vertex data (and buffer(s)) and configure vertex attributes
		// ------------------------------------------------------------------
		float vertices[] = {
			// positions          // colors           // texture coords
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
		};

		unsigned int indices[] = {
			0, 1, 3, // first triangle
			1, 2, 3  // second triangle
		};

		GLuint texture = LoadTexture("resources/textures/container.jpg", loader);

		while (window.GetEvent(report))
		{
			render.Begin();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			Mat4f projection;

			glMatrixMode(GL_PROJECTION);
			glLoadMatrixf(projection.Values());

			glEnable(GL_TEXTURE_2D);

			// bind Texture
			glBindTexture(GL_TEXTURE_2D, texture);

			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_COLOR_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);

			glVertexPointer(3, GL_FLOAT, 8 * sizeof(float), vertices);
			glColorPointer(3, GL_FLOAT, 8 * sizeof(float), &vertices[3]);
			glTexCoordPointer(2, GL_FLOAT, 8 * sizeof(float), &vertices[6]);

			Mat4f modelView;
			glMatrixMode(GL_MODELVIEW);
			modelView.Identity();
			modelView = Translate(modelView, Vec3f(0.5f, -0.5f, 0.0f));
			modelView = Rotate(modelView, (float)Ticks() / 1000.0f, Vec3f(0.0f, 0.0f, 1.0f));
			glLoadMatrixf(modelView.Values());

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indices);

			glDisableClientState(GL_VERTEX_ARRAY);
			glDisableClientState(GL_COLOR_ARRAY);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);

			render.End();

			if (report.Type == LDL::Events::IsResize)
			{
				glViewport(0, 0, (GLsizei)report.Resize.Width, (GLsizei)report.Resize.Height);
			}

            if (report.Type == IsQuit || report.IsKeyPressed(KeyboardKey::Escape))
            {
                window.StopEvent();
            }
		}
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}