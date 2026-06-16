/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <vector>
#include <iostream>
#include <cmath>
#include <LDL/C++98/LDL.hpp>

 // Простая замена Clock на системное время
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

class SimpleTimer
{
private:
	double startTime;
	double getTime()
	{
#ifdef _WIN32
		return (double)GetTickCount() / 1000.0;
#else
		struct timeval tv;
		gettimeofday(&tv, NULL);
		return tv.tv_sec + tv.tv_usec / 1000000.0;
#endif
	}
public:
	SimpleTimer() : startTime(0) {}
	void Start() { startTime = getTime(); }
	double GetElapsed() { return getTime() - startTime; }
};

int main()
{
	LDL::Result result;
	LDL::Context context(result);
	LDL::Event event;
	LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL C++98 - Animated Multilingual Greeting", LDL::Window::Resized);
	LDL::Render2D render(result, context, window);
	LDL::Font font(result, "Files/Lato-Bold.ttf", 42);
	LDL::Rasterizer rasterizer(result);
	SimpleTimer timer;

	// Тексты на разных языках
	const int languageCount = 8;
	const char* greetings[languageCount] = {
		"Hello, World!",
		"Привет, Мир!",
		"Hola, Mundo!",
		"Bonjour le monde!",
		"Ni hao, shijie!",
		"Konnichiwa sekai!",
		"Annyeonghaseyo segye!",
		"Marhaba bialealam!"
	};

	// Цвета для каждого языка
	LDL::Color colors[languageCount];
	colors[0] = LDL::Color(0, 162, 232);    // Голубой
	colors[1] = LDL::Color(34, 177, 76);    // Зеленый
	colors[2] = LDL::Color(237, 28, 36);    // Красный
	colors[3] = LDL::Color(0, 57, 166);     // Синий
	colors[4] = LDL::Color(255, 127, 39);   // Оранжевый
	colors[5] = LDL::Color(163, 73, 164);   // Фиолетовый
	colors[6] = LDL::Color(255, 201, 14);   // Желтый
	colors[7] = LDL::Color(255, 174, 201);  // Розовый

	// Создаем текстуры для каждого языка
	std::vector<LDL::Texture*> textures;
	for (int i = 0; i < languageCount; ++i)
	{
		rasterizer.Text(&font, colors[i], greetings[i]);
		textures.push_back(new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels()));
	}

	timer.Start();
	float elapsedTime = 0.0f;
	float lastTime = 0.0f;
	int currentLanguageIndex = 0;

	while (window.IsRunning() && result.IsOk())
	{
		float currentTime = (float)timer.GetElapsed();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		elapsedTime += deltaTime;

		while (window.GetEvent(event))
		{
			if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape))
			{
				window.StopEvent();
			}
			// Переключение языка по пробелу или стрелкам
			else if (event.IsKeyPressed(LDL_KeySpace) || event.IsKeyPressed(LDL_KeyRight))
			{
				currentLanguageIndex = (currentLanguageIndex + 1) % languageCount;
			}
			else if (event.IsKeyPressed(LDL_KeyLeft))
			{
				currentLanguageIndex = (currentLanguageIndex - 1 + languageCount) % languageCount;
			}
		}

		// Автоматическое переключение каждые 3 секунды
		if (elapsedTime >= 3.0f)
		{
			elapsedTime -= 3.0f;
			currentLanguageIndex = (currentLanguageIndex + 1) % languageCount;
		}

		render.Begin();

		// Градиентный фон
		for (int y = 0; y < 600; ++y)
		{
			float t = (float)y / 600.0f;
			LDL::Color bgColor(
				(unsigned char)(25 + t * 30),
				(unsigned char)(25 + t * 20),
				(unsigned char)(50 + t * 30)
			);
			render.SetColor(bgColor);
			render.Fill(LDL::Vec2i(0, y), LDL::Vec2i(800, 1));
		}

		// Анимированный "прыгающий" заголовок
		float bounce = sin(currentTime * 3.0f) * 25.0f;
		int yPos = 300 + (int)bounce;

		// Отображаем текущее приветствие (большое, по центру)
		if (currentLanguageIndex >= 0 && currentLanguageIndex < languageCount)
		{
			render.Draw(textures[currentLanguageIndex],
				LDL::Vec2i(400 - textures[currentLanguageIndex]->GetSize().x / 2, yPos));
		}

		render.End();
	}

	// Очистка памяти
	for (size_t j = 0; j < textures.size(); ++j)
	{
		delete textures[j];
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}