#include <iostream>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/OpenGL/OpenGL3_3.hpp>
#include "shader_s.h"

using namespace LDL::Graphics;

const std::string LessonTittle = "Lesson 03 - Adding Color";

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(800, 600), LessonTittle);

		RenderContext renderContext;
		Render render(&renderContext, &window);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::NumberToString convert;
		std::string title;

		// �������������� ����� ��������� ���������
		Shader ourShader("shaders/shader.vs", "shaders/shader.fs");  // ���� � ������ ��������

		// �������� ������ (� ������(��)) � ��������� ��������� ���������
		float vertices[] = {
			// ����������       // �����
			0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // ������ ������ �������
		   -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // ������ ����� �������
			0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // ������� �������
		};

		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		// ������� ��������� ������ ���������� �������, ����� ��������� � ������������� ��������� �����(�), � ����� ������������� ��������� �������(�)
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// ������������ ��������
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// �������� ��������
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		// ����� ����� �� ������ �������� �������� V��, ����� ������ ������ V�� �������� �� �������� ���� VAO, �� ��� ����� ����������.
		// ��������� ������ �������� VAO ������� ������ ������� glBindVertexArray() � ����� ������, ������� �� ������ �� ������� �������� VAO (��� VBO), ����� ��� ��������������� �� ���������
		// glBindVertexArray(0);

		// ���� ����������
		while (window.GetEvent(report))
		{
			fpsCounter.Start();

			render.Begin();

			// ���������        
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			// ��������� ������������
			ourShader.use();
			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);

			render.End();

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