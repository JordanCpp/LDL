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
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};

		// world space positions of our cubes
		Vec3f cubePositions[] = {
			Vec3f(0.0f,  0.0f,  0.0f),
			Vec3f(2.0f,  5.0f, -15.0f),
			Vec3f(-1.5f, -2.2f, -2.5f),
			Vec3f(-3.8f, -2.0f, -12.3f),
			Vec3f(2.4f, -0.4f, -3.5f),
			Vec3f(-1.7f,  3.0f, -7.5f),
			Vec3f(1.3f, -2.0f, -2.5f),
			Vec3f(1.5f,  2.0f, -2.5f),
			Vec3f(1.5f,  0.2f, -1.5f),
			Vec3f(-1.3f,  1.0f, -1.5f)
		};

		GLuint texture = LoadTexture("resources/textures/container.jpg", loader);

		// configure global opengl state
		// -----------------------------
		glEnable(GL_DEPTH_TEST);

		while (window.GetEvent(report))
		{
			render.Begin();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

			glEnable(GL_TEXTURE_2D);

			// bind Texture
			glBindTexture(GL_TEXTURE_2D, texture);

			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);

			glVertexPointer  (3, GL_FLOAT, 5 * sizeof(float), &vertices[0]);
			glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(float), &vertices[3]);


			// camera/view transformation
			Mat4f projection;
			Mat4f view; // make sure to initialize matrix to identity matrix first
			float radius = 10.0f;
			float camX = static_cast<float>(sin(Ticks() / 1000.0f) * radius);
			float camZ = static_cast<float>(cos(Ticks() / 1000.0f) * radius);
			view = LookAt(Vec3f(camX, 0.0f, camZ), Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f, 1.0f, 0.0f));

			projection = Perspective(45.0f, (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
			glMatrixMode(GL_PROJECTION);
			glLoadMatrixf(projection.Values());

			for (size_t i = 0; i < 10; i++)
			{
				// calculate the model matrix for each object and pass it to shader before drawing
				Mat4f model;
				model = Translate(model, cubePositions[i]);
				float angle = 20.0f * i;
				model = Rotate(model, angle, Vec3f(1.0f, 0.3f, 0.5f));
				Mat4f modelView = model * view;

				glMatrixMode(GL_MODELVIEW);
				glLoadMatrixf(modelView.Values());;

				glDrawArrays(GL_TRIANGLES, 0, 36);
			}

			glDisableClientState(GL_VERTEX_ARRAY);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);

			render.End();

			if (report.Type == LDL::Events::IsResize)
			{
				glViewport(0, 0, (GLsizei)report.Resize.Width, (GLsizei)report.Resize.Height);
			}

            if (report.Type == IsQuit || report.IsKeyPresed(KeyboardKey::Escape))
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