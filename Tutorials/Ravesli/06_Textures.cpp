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

using namespace LDL::Graphics;

const std::string LessonTittle = "Lesson 03 - Adding Color";

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(800, 600), LessonTittle);

        RenderContext renderContext;
        Render render(&renderContext, &window);

        LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 4);
        LDL::Loaders::ImageLoader loader(&allocator);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;
        std::string title;

        // Компилирование нашей шейдерной программы
        Shader ourShader("shaders/4.2.texture.vs", "shaders/4.2.texture.fs");

        // Указание вершин (и буфера(ов)) и настройка вершинных атрибутов
        float vertices[] = {
            // координаты        // цвета            // текстурные координаты
            0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // верхняя правая вершина
            0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // нижняя правая вершина
           -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // нижняя левая вершина
           -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // верхняя левая вершина 
        };
        unsigned int indices[] = {
            0, 1, 3, // первый треугольник
            1, 2, 3  // второй треугольник
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

        // Координатные атрибуты
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Цветовые атрибуты
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // Атрибуты текстурных координат
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);


        // Загрузка и создание текстуры
        unsigned int texture1, texture2;

        // Текстура №1 - Деревянный ящик
        glGenTextures(1, &texture1);
        glBindTexture(GL_TEXTURE_2D, texture1);

        // Установка параметров наложения текстуры
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // установка метода наложения текстуры GL_REPEAT (стандартный метод наложения)
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
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // установка метода наложения текстуры GL_REPEAT (стандартный метод наложения)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        // Установка параметров фильтрации текстуры
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Загрузка изображения, создание текстуры и генерирование мипмап-уровней
        loader.Load("textures/awesomeface.png");

        // Файл awesomeface.png имеет альфа-канал (прозрачность), поэтому необходимо использовать пераметр GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (GLsizei)loader.Size().PosX(), (GLsizei)loader.Size().PosY(), 0, GL_RGBA, GL_UNSIGNED_BYTE, loader.Pixels());
        glGenerateMipmap(GL_TEXTURE_2D);

        // Указываем OpenGL, какой сэмплер к какому текстурному блоку принадлежит (это нужно сделать единожды) 
        ourShader.use(); // не забудьте активировать шейдер перед настройкой uniform-переменных!  
        // Устанавливаем вручную…
        glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0);
        // …или с помощью шейдерного класса
        ourShader.setInt("texture2", 1);

        // Цикл рендеринга
		while (window.GetEvent(report))
		{
			fpsCounter.Start();

			render.Begin();

            // Рендеринг
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Привязка текстур к соответствующим текстурным юнитам
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture1);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, texture2);

            // Рендеринг ящика
            ourShader.use();
            glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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

        // Опционально: освобождаем все ресурсы, как только они выполнили свое предназначение
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}