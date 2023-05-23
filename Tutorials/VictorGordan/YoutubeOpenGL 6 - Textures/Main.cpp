#include<iostream>

#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Events/Event.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/Ticks.hpp>

#include <LDL/Math/Mat4f.hpp>
#include <LDL/Math/Vec3f.hpp>
#include <LDL/Math/Funcs.hpp>

#include <LDL/OpenGL/OpenGL3_3.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Enums;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;
using namespace LDL::Time;

#include "Texture2D.h"
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

const size_t width  = 800;
const size_t height = 800;

// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Lower left corner
	-0.5f,  0.5f, 0.0f,     0.0f, 1.0f, 0.0f,	0.0f, 1.0f, // Upper left corner
	 0.5f,  0.5f, 0.0f,     0.0f, 0.0f, 1.0f,	1.0f, 1.0f, // Upper right corner
	 0.5f, -0.5f, 0.0f,     1.0f, 1.0f, 1.0f,	1.0f, 0.0f  // Lower right corner
};

// Indices for vertices order
GLuint indices[] =
{
	0, 2, 1, // Upper triangle
	0, 3, 2 // Lower triangle
};

int main()
{
	try 
	{
		Window window(Point2u(0, 0), Point2u(width, height), "YoutubeOpenGL");

		RenderContext renderContext;
		Render render(&renderContext, &window);

		FixedLinear allocator(Allocator::Mb * 64);
		ImageLoader loader(&allocator);

		LDL::Events::Event report;

		/*
		* I'm doing this relative path thing in order to centralize all the resources into one folder and not
		* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
		* folder and then give a relative path from this folder to whatever resource you want to get to.
		* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
		*/
		std::string parentDir = "";
		std::string texPath = "Resources/YoutubeOpenGL 6 - Textures/";

		// Generates Shader object using shaders default.vert and default.frag
		Shader shaderProgram(parentDir + texPath + "default.vert", parentDir + texPath + "default.frag");

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

		// Texture
		Texture2D popCat(parentDir + texPath + "pop_cat.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE, loader);
		popCat.texUnit(shaderProgram, "tex0", 0);

		// Original code from the tutorial
		/*Texture popCat("pop_cat.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
		popCat.texUnit(shaderProgram, "tex0", 0);*/

		// Main while loop                                                   

		while (window.GetEvent(report))
		{
			render.Begin();

			// Specify the color of the background
			glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
			// Clean the back buffer and assign the new color to it
			glClear(GL_COLOR_BUFFER_BIT);
			// Tell OpenGL which Shader Program we want to use
			shaderProgram.Activate();
			// Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
			glUniform1f(uniID, 0.5f);
			// Binds texture so that is appears in rendering
			popCat.Bind();
			// Bind the VAO so OpenGL knows to use it
			VAO1.Bind();
			// Draw primitives, number of indices, datatype of indices, index of indices
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			render.End();

			if (report.Type == IsResize)
			{
				glViewport(0, 0, (GLsizei)report.Resize.Width, (GLsizei)report.Resize.Height);
			}

			if (report.Type == IsQuit || report.IsKeyPressed(KeyboardKey::Escape))
			{
				window.StopEvent();
			}
		}

		// Delete all the objects we've created
		VAO1.Delete();
		VBO1.Delete();
		EBO1.Delete();
		popCat.Delete();
		shaderProgram.Delete();
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}