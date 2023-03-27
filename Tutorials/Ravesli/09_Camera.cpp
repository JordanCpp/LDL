#include <iostream>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>
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
float lastX = 800 / 2.0f;
float lastY = 600 / 2.0f;

bool firstMouse = true;

// Тайминги
float deltaTime = 0.0f;	// время между текущим кадром и последним кадром
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
		LDL::Core::IntegerToString convert;
		LDL::Time::FpsLimiter fpsLimiter;
		std::string title;

		// Конфигурирование глобального состояния OpenGL
		glEnable(GL_DEPTH_TEST);

		// Компилирование нашей шейдерной программы
		Shader ourShader("shaders/7.4.camera.vs", "shaders/7.4.camera.fs");

		// Указание вершин (и буфера(ов)) и настройка вершинных атрибутов
		float vertices[] = {
			// координаты        // текстурные координаты
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

		// Мировые координаты наших кубиков
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

		// Координатные атрибуты
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// Атрибуты текстурных координат
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);


		// Загрузка и создание текстур
		unsigned int texture1, texture2;

		// Текстура №1 - Деревянный ящик
		glGenTextures(1, &texture1);
		glBindTexture(GL_TEXTURE_2D, texture1);

		// Установка параметров наложения текстуры
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// Установка параметров фильтрации текстуры
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Загрузка изображения, создание текстуры и генерирование мипмап-уровней
        loader.Load("textures/wooden_container.jpg");

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (GLsizei)loader.Size().PosX(), (GLsizei)loader.Size().PosY(), 0, GL_RGB, GL_UNSIGNED_BYTE, loader.Pixels());
        glGenerateMipmap(GL_TEXTURE_2D);

		// Текстура №2 - Смайлик
		glGenTextures(1, &texture2);
		glBindTexture(GL_TEXTURE_2D, texture2);

		// Установка параметров наложения текстуры
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// Установка параметров фильтрации текстуры
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Указываем OpenGL, какой сэмплер к какому текстурному блоку принадлежит (это нужно сделать единожды) 
		ourShader.use();
		ourShader.setInt("texture1", 0);
		ourShader.setInt("texture2", 1);

        // Цикл рендеринга
		while (window.GetEvent(report))
		{
			fpsLimiter.Mark();

			fpsCounter.Start();

			render.Begin();

			// Логическая часть работы со временем для каждого кадра
			float currentFrame = (float)LDL::Time::Ticks();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			// Рендеринг
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очищаем буфер цвета и буфер глубины

			// Привязка текстур к соответствующим текстурным юнитам
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture1);
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, texture2);

			// Активируем шейдер
			ourShader.use();

			// Передаем шейдеру матрицу проекции (поскольку проекционная матрица редко меняется, то нет необходимости делать это для каждого кадра)
			Mat4f projection = Perspective(camera.Zoom, (float)window.Size().PosX() / (float)window.Size().PosY(), 0.1f, 100.0f);
			ourShader.setMat4("projection", projection);

			// Создаем преобразование камеры/вида
			Mat4f view = camera.GetViewMatrix();
			ourShader.setMat4("view", view);

			// Рендерим ящик
			glBindVertexArray(VAO);

			for (size_t i = 0; i < 10; i++)
			{
				// Вычисляем матрицу модели для каждого объекта и передаем её в шейдер до отрисовки
				Mat4f model;
				model = Translate(model, cubePositions[i]);
				float angle = 20.0f * i;
				model = Rotate(model, angle, Vec3f(1.0f, 0.3f, 0.5f));
				ourShader.setMat4("model", model);

				glDrawArrays(GL_TRIANGLES, 0, 36);
			}

			render.End();

			fpsLimiter.Throttle();

			if (report.Type == LDL::Events::IsKeyboard && report.Keyboard.State == LDL::Enums::ButtonState::Released)
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
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}