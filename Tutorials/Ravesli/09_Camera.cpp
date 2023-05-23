#include <iostream>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/OpenGL/OpenGL3_3.hpp>

#include "shader_s.h"
#include "camera.h" 
#include <LDL/Time/FpsLimiter.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Enums;

const std::string LessonTittle = "Lesson 03 - Adding Color";

// ���������
const size_t SCR_WIDTH  = 800;
const size_t SCR_HEIGHT = 600;

// ������
Camera camera(Vec3f(0.0f, 0.0f, 3.0f));
float lastX = 800 / 2.0f;
float lastY = 600 / 2.0f;

bool firstMouse = true;

// ��������
float deltaTime = 0.0f;	// ����� ����� ������� ������ � ��������� ������
float lastFrame = 0.0f;

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(SCR_WIDTH, SCR_HEIGHT), LessonTittle);

		RenderContext renderContext;
		Render render(&renderContext, &window);

        LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 4);
        LDL::Loaders::ImageLoader loader(&allocator);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::NumberToString convert;
		LDL::Time::FpsLimiter fpsLimiter;
		std::string title;

		// ���������������� ����������� ��������� OpenGL
		glEnable(GL_DEPTH_TEST);

		// �������������� ����� ��������� ���������
		Shader ourShader("shaders/7.4.camera.vs", "shaders/7.4.camera.fs");

		// �������� ������ (� ������(��)) � ��������� ��������� ���������
		float vertices[] = {
			// ����������        // ���������� ����������
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

		// ������� ���������� ����� �������
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

		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// ������������ ��������
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// �������� ���������� ���������
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);


		// �������� � �������� �������
		unsigned int texture1, texture2;

		// �������� �1 - ���������� ����
		glGenTextures(1, &texture1);
		glBindTexture(GL_TEXTURE_2D, texture1);

		// ��������� ���������� ��������� ��������
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// ��������� ���������� ���������� ��������
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // �������� �����������, �������� �������� � ������������� ������-�������
        loader.Load("textures/wooden_container.jpg");

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (GLsizei)loader.Size().PosX(), (GLsizei)loader.Size().PosY(), 0, GL_RGB, GL_UNSIGNED_BYTE, loader.Pixels());
        glGenerateMipmap(GL_TEXTURE_2D);

		// �������� �2 - �������
		glGenTextures(1, &texture2);
		glBindTexture(GL_TEXTURE_2D, texture2);

		// ��������� ���������� ��������� ��������
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// ��������� ���������� ���������� ��������
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// ��������� OpenGL, ����� ������� � ������ ����������� ����� ����������� (��� ����� ������� ��������) 
		ourShader.use();
		ourShader.setInt("texture1", 0);
		ourShader.setInt("texture2", 1);

        // ���� ����������
		while (window.GetEvent(report))
		{
			fpsLimiter.Mark();

			fpsCounter.Start();

			render.Begin();

			// ���������� ����� ������ �� �������� ��� ������� �����
			float currentFrame = (float)LDL::Time::Ticks() / 1000.0f;
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			// ���������
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ������� ����� ����� � ����� �������

			// �������� ������� � ��������������� ���������� ������
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture1);
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, texture2);

			// ���������� ������
			ourShader.use();

			// �������� ������� ������� �������� (��������� ������������ ������� ����� ��������, �� ��� ������������� ������ ��� ��� ������� �����)
			Mat4f projection = Perspective(camera.Zoom, (float)window.Size().PosX() / (float)window.Size().PosY(), 0.1f, 100.0f);
			ourShader.setMat4("projection", projection);

			// ������� �������������� ������/����
			Mat4f view = camera.GetViewMatrix();
			ourShader.setMat4("view", view);

			// �������� ����
			glBindVertexArray(VAO);

			for (size_t i = 0; i < 10; i++)
			{
				// ��������� ������� ������ ��� ������� ������� � �������� � � ������ �� ���������
				Mat4f model;
				model = Translate(model, cubePositions[i]);
				float angle = 20.0f * i;
				model = Rotate(model, angle, Vec3f(1.0f, 0.3f, 0.5f));
				ourShader.setMat4("model", model);

				glDrawArrays(GL_TRIANGLES, 0, 36);
			}

			render.End();

			fpsLimiter.Throttle();

			if (report.IsKeyPressed(KeyboardKey::W))
				camera.ProcessKeyboard(FORWARD, deltaTime);

			if (report.IsKeyPressed(KeyboardKey::S))
				camera.ProcessKeyboard(BACKWARD, deltaTime);

			if (report.IsKeyPressed(KeyboardKey::A))
				camera.ProcessKeyboard(LEFT, deltaTime);

			if (report.IsKeyPressed(KeyboardKey::D))
				camera.ProcessKeyboard(RIGHT, deltaTime);

			if (report.Type == IsMouseMove)
			{
				float xpos = (float)report.Mouse.PosX;
				float ypos = (float)report.Mouse.PosY;

				if (firstMouse)
				{
					lastX = xpos;
					lastY = ypos;
					firstMouse = false;
				}

				float xoffset = xpos - lastX;
				float yoffset = lastY - ypos; // �����������, ��� ��� y-���������� ���� ����� �����

				lastX = xpos;
				lastY = ypos;

				camera.ProcessMouseMovement(xoffset, yoffset);
			}

			if (report.Type == LDL::Events::IsResize)
			{
				glViewport(0, 0, (GLsizei)report.Resize.Width, (GLsizei)report.Resize.Height);
			}

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

		// �����������: ����������� ��� �������, ��� ������ ��� ��������� ���� ��������������
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}