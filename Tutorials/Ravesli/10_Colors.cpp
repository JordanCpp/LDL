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

const std::string LessonTittle = "Lesson 03 - Adding Color";

// Константы
const size_t SCR_WIDTH  = 800;
const size_t SCR_HEIGHT = 600;

// Камера
Camera camera(Vec3f(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// Тайминги
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// Освещение
Vec3f lightPos(1.2f, 1.0f, 2.0f);

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

		// Конфигурирование глобального состояния OpenGL
		glEnable(GL_DEPTH_TEST);

		// Компилирование нашей шейдерной программы
		Shader lightingShader("shaders/1.colors.vs", "shaders/1.colors.fs");
		Shader lampShader("shaders/1.lamp.vs", "shaders/1.lamp.fs");

		// Указание вершин (и буфера(ов)) и настройка вершинных атрибутов
		float vertices[] = {
			-0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f, -0.5f,
			 0.5f,  0.5f, -0.5f,
			 0.5f,  0.5f, -0.5f,
			-0.5f,  0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,

			-0.5f, -0.5f,  0.5f,
			 0.5f, -0.5f,  0.5f,
			 0.5f,  0.5f,  0.5f,
			 0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f,  0.5f,
			-0.5f, -0.5f,  0.5f,

			-0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,
			-0.5f, -0.5f,  0.5f,
			-0.5f,  0.5f,  0.5f,

			 0.5f,  0.5f,  0.5f,
			 0.5f,  0.5f, -0.5f,
			 0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f,  0.5f,
			 0.5f,  0.5f,  0.5f,

			-0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f,  0.5f,
			 0.5f, -0.5f,  0.5f,
			-0.5f, -0.5f,  0.5f,
			-0.5f, -0.5f, -0.5f,

			-0.5f,  0.5f, -0.5f,
			 0.5f,  0.5f, -0.5f,
			 0.5f,  0.5f,  0.5f,
			 0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f, -0.5f,
		};

		// 1. Настраиваем VAO (и VBO)
		unsigned int VBO, cubeVAO;
		glGenVertexArrays(1, &cubeVAO);
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindVertexArray(cubeVAO);

		// Координатные атрибуты
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// 2. Настраиваем VAO света (VBO остается неизменным; вершины те же и для светового объекта, который также является 3D-кубом)
		unsigned int lightVAO;
		glGenVertexArrays(1, &lightVAO);
		glBindVertexArray(lightVAO);

		// Нам нужно только привязаться к VBO (чтобы связать его с glVertexAttribPointer), нам не нужно его заполнять; данные VBO уже содержат всё, что нам нужно (они уже привязаны, но мы делаем это снова в образовательных целях) 
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// Цикл рендеринга
		while (window.GetEvent(report))
		{
			fpsLimiter.Mark();

			fpsCounter.Start();

			render.Begin();

			// Логическая часть работы со временем для каждого кадра
			float currentFrame = (float)LDL::Time::Ticks() / 1000.f;
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			// Рендеринг
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Убеждаемся, что активировали шейдер прежде, чем настраивать uniform-переменные/объекты_рисования
			lightingShader.use();
			lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
			lightingShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);

			// Преобразования Вида/Проекции
			Mat4f projection = Perspective(camera.Zoom, (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
			Mat4f view = camera.GetViewMatrix();
			lightingShader.setMat4("projection", projection);
			lightingShader.setMat4("view", view);

			// Мировое преобразование
			Mat4f model;
			lightingShader.setMat4("model", model);

			// Рендеринг куба
			glBindVertexArray(cubeVAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);

			// Также отрисовываем наш объект-"лампочку" 
			lampShader.use();
			lampShader.setMat4("projection", projection);
			lampShader.setMat4("view", view);
			model = Translate(model, lightPos);
			model = Scale(model, Vec3f(0.2f)); // куб меньшего размера
			lampShader.setMat4("model", model);

			glBindVertexArray(lightVAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);

			render.End();

			fpsLimiter.Throttle();

			if (report.Type == LDL::Events::IsKeyboard && report.Keyboard.State == LDL::Enums::ButtonState::Pressed)
			{
				if (report.Keyboard.Key == LDL::Enums::KeyboardKey::W)
					camera.ProcessKeyboard(FORWARD, deltaTime);

				if (report.Keyboard.Key == LDL::Enums::KeyboardKey::S)
					camera.ProcessKeyboard(BACKWARD, deltaTime);

				if (report.Keyboard.Key == LDL::Enums::KeyboardKey::A)
					camera.ProcessKeyboard(LEFT, deltaTime);

				if (report.Keyboard.Key == LDL::Enums::KeyboardKey::D)
					camera.ProcessKeyboard(RIGHT, deltaTime);
			}

			if (report.Type == LDL::Events::IsMouseMove)
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
				float yoffset = lastY - ypos; // перевернуто, так как y-координаты идут снизу вверх

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

		// Опционально: освобождаем все ресурсы, как только они выполнили свое предназначение
		glDeleteVertexArrays(1, &cubeVAO);
		glDeleteVertexArrays(1, &lightVAO);
		glDeleteBuffers(1, &VBO);
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}