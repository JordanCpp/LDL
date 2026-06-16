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
	LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL C++98 - Font Size Gallery", LDL::Window::Resized);
	LDL::Render2D render(result, context, window);
	LDL::Rasterizer rasterizer(result);
	SimpleTimer timer;

	// Создаем шрифты разных размеров
	LDL::Font font16(result, "Files/Lato-Bold.ttf", 16);
	LDL::Font font24(result, "Files/Lato-Bold.ttf", 24);
	LDL::Font font32(result, "Files/Lato-Bold.ttf", 32);
	LDL::Font font48(result, "Files/Lato-Bold.ttf", 48);
	LDL::Font font64(result, "Files/Lato-Bold.ttf", 64);
	LDL::Font font72(result, "Files/Lato-Bold.ttf", 72);

	// Массивы с информацией о шрифтах
	const int fontCount = 6;
	LDL::Font* fonts[fontCount] = { &font16, &font24, &font32, &font48, &font64, &font72 };
	const char* sizeLabels[fontCount] = { "16px", "24px", "32px", "48px", "64px", "72px" };

	LDL::Color fontColors[fontCount];
	fontColors[0] = LDL::Color(255, 100, 100);   // Красный
	fontColors[1] = LDL::Color(255, 150, 50);    // Оранжевый
	fontColors[2] = LDL::Color(255, 255, 100);   // Желтый
	fontColors[3] = LDL::Color(100, 255, 100);   // Зеленый
	fontColors[4] = LDL::Color(100, 150, 255);   // Синий
	fontColors[5] = LDL::Color(200, 100, 255);   // Фиолетовый

	// Создаем текстуры для каждого размера
	std::vector<LDL::Texture*> labelTextures;
	std::vector<LDL::Texture*> sampleTextures;

	for (int i = 0; i < fontCount; i++)
	{
		// Текстура с названием размера
		rasterizer.Text(fonts[i], fontColors[i], sizeLabels[i]);
		labelTextures.push_back(new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels()));

		// Текстура с примером текста
		rasterizer.Text(fonts[i], fontColors[i], "The quick brown fox jumps over the lazy dog");
		sampleTextures.push_back(new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels()));
	}

	// Шрифт для заголовка
	LDL::Font titleFont(result, "Files/Lato-Bold.ttf", 28);

	timer.Start();
	float currentTime = 0.0f;
	float lastTime = 0.0f;
	int selectedFont = 0;
	float selectionTimer = 0.0f;

	while (window.IsRunning() && result.IsOk())
	{
		currentTime = (float)timer.GetElapsed();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		selectionTimer += deltaTime;

		while (window.GetEvent(event))
		{
			if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape))
			{
				window.StopEvent();
			}
			// Выбор шрифта стрелками вверх/вниз
			else if (event.IsKeyPressed(LDL_KeyUp))
			{
				selectedFont = (selectedFont - 1 + fontCount) % fontCount;
				selectionTimer = 0.0f;
			}
			else if (event.IsKeyPressed(LDL_KeyDown))
			{
				selectedFont = (selectedFont + 1) % fontCount;
				selectionTimer = 0.0f;
			}
			// Быстрый выбор цифрами 1-6
			else if (event.IsKeyPressed(LDL_KeyNum1)) { selectedFont = 0; selectionTimer = 0.0f; }
			else if (event.IsKeyPressed(LDL_KeyNum2)) { selectedFont = 1; selectionTimer = 0.0f; }
			else if (event.IsKeyPressed(LDL_KeyNum3)) { selectedFont = 2; selectionTimer = 0.0f; }
			else if (event.IsKeyPressed(LDL_KeyNum4)) { selectedFont = 3; selectionTimer = 0.0f; }
			else if (event.IsKeyPressed(LDL_KeyNum5)) { selectedFont = 4; selectionTimer = 0.0f; }
			else if (event.IsKeyPressed(LDL_KeyNum6)) { selectedFont = 5; selectionTimer = 0.0f; }
		}

		// Автоматическое переключение каждые 3 секунды
		if (selectionTimer >= 3.0f)
		{
			selectionTimer -= 3.0f;
			selectedFont = (selectedFont + 1) % fontCount;
		}

		render.Begin();

		// Темный фон
		render.SetColor(LDL::Color(30, 30, 40));
		render.Clear();

		// Заголовок
		rasterizer.Text(&titleFont, LDL::Color(255, 255, 200), "Font Size Gallery");
		LDL::Texture titleTexture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels());
		render.Draw(&titleTexture, LDL::Vec2i(400 - titleTexture.GetSize().x / 2, 10));

		// Подсказка по управлению
		LDL::Font hintFont(result, "Files/Lato-Bold.ttf", 14);
		rasterizer.Text(&hintFont, LDL::Color(150, 150, 150), "Arrows Up/Down or keys 1-6 to select font size");
		LDL::Texture hintTexture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels());
		render.Draw(&hintTexture, LDL::Vec2i(400 - hintTexture.GetSize().x / 2, 45));

		// Отображаем все размеры шрифтов в галерее
		int startY = 80;
		int spacing = 80;

		for (int i = 0; i < fontCount; i++)
		{
			int yPos = startY + i * spacing;

			// Подсветка выбранного шрифта
			if (i == selectedFont)
			{
				// Фоновая подсветка
				float glowIntensity = sin(currentTime * 3.0f) * 0.3f + 0.7f;
				render.SetColor(LDL::Color(
					(unsigned char)(fontColors[i].r * glowIntensity),
					(unsigned char)(fontColors[i].g * glowIntensity * 0.3f),
					(unsigned char)(fontColors[i].b * glowIntensity * 0.3f)
				));
				render.Fill(LDL::Vec2i(10, yPos - 5), LDL::Vec2i(780, spacing - 10));

				// Рамка выбранного элемента
				render.SetColor(fontColors[i]);
				render.Fill(LDL::Vec2i(10, yPos - 5), LDL::Vec2i(4, spacing - 10));
				render.Fill(LDL::Vec2i(786, yPos - 5), LDL::Vec2i(4, spacing - 10));

				// Анимированный индикатор слева
				float indicatorOffset = sin(currentTime * 5.0f) * 10.0f;
				render.Fill(LDL::Vec2i(14 + (int)indicatorOffset, yPos + 5), LDL::Vec2i(20, 4));
			}

			// Название размера (слева)
			render.Draw(labelTextures[i], LDL::Vec2i(50, yPos + 10));

			// Пример текста (справа от названия)
			int sampleX = 50 + labelTextures[i]->GetSize().x + 20;
			render.Draw(sampleTextures[i], LDL::Vec2i(sampleX, yPos + 10));

			// Линия-разделитель
			if (i < fontCount - 1)
			{
				render.SetColor(LDL::Color(60, 60, 70));
				render.Fill(LDL::Vec2i(50, yPos + spacing - 2), LDL::Vec2i(700, 1));
			}
		}

		// Информация о выбранном шрифте внизу
		char infoText[100];
		sprintf(infoText, "Selected: %s - Sample text shows how this size renders", sizeLabels[selectedFont]);

		rasterizer.Text(&hintFont, fontColors[selectedFont], infoText);
		LDL::Texture infoTexture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels());
		render.Draw(&infoTexture, LDL::Vec2i(400 - infoTexture.GetSize().x / 2, 560));

		// Индикатор авто-переключения
		float progress = selectionTimer / 3.0f;
		render.SetColor(LDL::Color(40, 40, 50));
		render.Fill(LDL::Vec2i(300, 580), LDL::Vec2i(200, 6));
		render.SetColor(fontColors[selectedFont]);
		render.Fill(LDL::Vec2i(300, 580), LDL::Vec2i((int)(200 * progress), 6));

		render.End();
	}

	// Очистка памяти
	for (size_t i = 0; i < labelTextures.size(); i++)
	{
		delete labelTextures[i];
		delete sampleTextures[i];
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}