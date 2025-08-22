#include <math.h>
#include <LDL/LDL.hpp>
#include <LDL/APIs/OpenGL/OpenGL3_3.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>  

#include "GordanLib/Texture.h"
#include "GordanLib/shaderClass.h"
#include "GordanLib/VAO.h"
#include "GordanLib/VBO.h"
#include "GordanLib/EBO.h"  

using namespace LDL::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;

const unsigned int width = 800;
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
		RenderContext renderContext(RenderMode::OpenGL3);

		Window window(renderContext, Vec2u(0, 0), Vec2u(800, 800), "YoutubeOpenGL");
		Render render(renderContext, &window);

		Event report;

		FpsCounter fpsCounter;
		Convert convert;
		FpsLimiter fpsLimiter;

		FixedLinear allocator(Allocator::Mb * 64);
		ImageLoader loader(&allocator);

		// Specify the viewport of OpenGL in the Window
		// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
		glViewport(0, 0, (GLsizei)window.Size().x, (GLsizei)window.Size().y);

		// Generates Shader object using shaders default.vert and default.frag
		Shader shaderProgram("Data/Shaders/07_Going3D/default.vert", "Data/Shaders/07_Going3D/default.frag");

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

		// Gets ID of uniform called "scale"
		GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

		loader.Load("Data/Textures/brick.png");

		// Texture
		TextureGL brickTex(loader, GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
		brickTex.texUnit(shaderProgram, "tex0", 0);

		// Original code from the tutorial
		/*Texture brickTex("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
		brickTex.texUnit(shaderProgram, "tex0", 0);*/

		// Variables that help the rotation of the pyramid
		float rotation = 0.0f;
		double prevTime = (double)Ticks();

		// Enables the Depth Buffer
		glEnable(GL_DEPTH_TEST);

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
			}

			render.Begin();

			// Specify the color of the background
			glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
			// Clean the back buffer and depth buffer
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			// Tell OpenGL which Shader Program we want to use
			shaderProgram.Activate();

			// Simple timer
			double crntTime = (double)Ticks();
			if (crntTime - prevTime >= 1 / 60)
			{
				rotation += 0.5f;
				prevTime = crntTime;
			}

			// Initializes matrices so they are not the null matrix
			glm::mat4 model = glm::mat4(1.0f);
			glm::mat4 view = glm::mat4(1.0f);
			glm::mat4 proj = glm::mat4(1.0f);

			// Assigns different transformations to each matrix
			model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
			view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
			proj = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

			// Outputs the matrices into the Vertex Shader
			int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
			int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
			glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

			// Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
			glUniform1f(uniID, 0.5f);
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
