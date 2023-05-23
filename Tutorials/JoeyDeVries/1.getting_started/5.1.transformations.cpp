#include <iostream>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Time/Ticks.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/OpenGL/OpenGL3_3.hpp>

#include <LDL/Math/Mat4f.hpp>
#include <LDL/Math/Vec3f.hpp>
#include <LDL/Math/Funcs.hpp>

#include <learnopengl/shader_s.h> 
#include <learnopengl/texture.h>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Enums;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;
using namespace LDL::Time;

// settings
const unsigned int SCR_WIDTH  = 800;
const unsigned int SCR_HEIGHT = 600;

// stores how much we're seeing of either texture
float mixValue = 0.2f;

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

        // build and compile our shader zprogram
        // ------------------------------------
        Shader ourShader("resources/shaders/5.1.transform.vs", "resources/shaders/5.1.transform.fs");

        // set up vertex data (and buffer(s)) and configure vertex attributes
        // ------------------------------------------------------------------
        float vertices[] = {
            // positions          // texture coords
             0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
             0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
            -0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // top left 
        };
        unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
        };
        unsigned int VBO, VAO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // texture coord attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);


        // load and create a texture 
        // -------------------------
        GLuint texture1 = LoadTexture("resources/textures/container.jpg", loader);
        GLuint texture2 = LoadTexture("resources/textures/awesomeface.png", loader);

        // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
        // -------------------------------------------------------------------------------------------
        ourShader.use();
        ourShader.setInt("texture1", 0);
        ourShader.setInt("texture2", 1);


        // render loop
        // ----------- 

		while (window.GetEvent(report))
		{
			render.Begin();

            // render
            // ------
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // bind textures on corresponding texture units
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture1);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, texture2);

            // create transformations
            Mat4f transform; // make sure to initialize matrix to identity matrix first
            transform = Translate(transform, Vec3f(0.5f, -0.5f, 0.0f));
            transform = Rotate(transform, (float)Ticks() / 1000.0f, Vec3f(0.0f, 0.0f, 1.0f));

            // get matrix's uniform location and set matrix
            ourShader.use();
            unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, transform.Values());

            // render container
            glBindVertexArray(VAO);
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

        // optional: de-allocate all resources once they've outlived their purpose:
        // ------------------------------------------------------------------------
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}