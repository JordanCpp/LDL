#include <LDL/LDL.hpp>
#include <LDL/APIs/OpenGL/OpenGL3_3.hpp> 

#include "GordanLib/Texture.h"
#include "GordanLib/shaderClass.h"
#include "GordanLib/VAO.h"
#include "GordanLib/VBO.h"
#include "GordanLib/EBO.h"  
#include "GordanLib/Camera.hpp" 

using namespace LDL::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;

const unsigned int width  = 800;
const unsigned int height = 800;

// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
};

int main()
{
	Result result;
		RenderContext renderContext(RenderMode::OpenGL3);

		Window window(result, renderContext, Vec2u(0, 0), Vec2u(width, height), "YoutubeOpenGL");
		Render render(result, renderContext, &window);

		Event report;

		FpsCounter fpsCounter;
		Convert convert;
		FpsLimiter fpsLimiter;

		FixedLinear allocator(Allocator::Mb * 64);
		ImageLoader loader(&allocator);

		// Generates Shader object using shaders default.vert and default.frag
		Shader shaderProgram("Data/Shaders/08_Camera/default.vert", "Data/Shaders/08_Camera/default.frag");

		// Generates Vertex Array Object and binds it
		VAO VAO1;
		VAO1.Bind();

		// Generates Vertex Buffer Object and links it to vertices
		VBO VBO1(vertices, sizeof(vertices));
		// Generates Element Buffer Object and links it to indices
		EBO EBO1(indices, sizeof(indices));

		// Links VBO attributes such as coordinates and colors to VAO
		VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		// Unbind all to prevent accidentally modifying them
		VAO1.Unbind();
		VBO1.Unbind();
		EBO1.Unbind();

		loader.Load("Data/Textures/brick.png");

		// Texture
		TextureGL brickTex(loader, GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
		brickTex.texUnit(shaderProgram, "tex0", 0);

		// Enables the Depth Buffer
		glEnable(GL_DEPTH_TEST);

		// Creates camera object
		Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

		while (window.Running())
		{
			fpsLimiter.Mark();
			fpsCounter.Start();

			while (window.GetEvent(report))
			{
				if (report.Type == IsQuit)
				{
					window.StopEvent();
				}

				if (report.IsKeyPressed(KeyboardKey::Escape))
					window.StopEvent();

				// Handles camera inputs
				camera.Inputs(report);
			}

			render.Begin();

			// Specify the color of the background
			glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
			// Clean the back buffer and depth buffer
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			// Tell OpenGL which Shader Program we want to use
			shaderProgram.Activate();

			// Updates and exports the camera matrix to the Vertex Shader
			camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

			// Binds texture so that is appears in rendering
			brickTex.Bind();
			// Bind the VAO so OpenGL knows to use it
			VAO1.Bind();
			// Draw primitives, number of indices, datatype of indices, index of indices
			glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

			render.End();

			fpsLimiter.Throttle();

			if (fpsCounter.Calc())
			{
				window.Title(convert.ToString(fpsCounter.Fps()));
				fpsCounter.Clear();
			}

			window.PollEvents();
		}

		// Delete all the objects we've created
		VAO1.Delete();
		VBO1.Delete();
		EBO1.Delete();
		brickTex.Delete();
		shaderProgram.Delete();

	return 0;
}
