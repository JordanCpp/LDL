/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <LDL/C++98/LDL.hpp>

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

struct Spark
{
	float x, y;
	float vx, vy;
	float life;
	float maxLife;
	int colorIndex;
};

int randomRange(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

float randomFloat()
{
	return (float)rand() / (float)RAND_MAX;
}

int main()
{
	srand((unsigned int)time(NULL));

	LDL::Result result;
	LDL::Context context(result);
	LDL::Event event;
	LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600),
		"LDL C++98 - Fire Text with Particles", LDL::Window::Resized);
	LDL::Render2D render(result, context, window);
	LDL::Rasterizer rasterizer(result);
	SimpleTimer timer;

	// Увеличенный шрифт для огненного текста
	LDL::Font fireFont(result, "Files/Lato-Bold.ttf", 96);
	LDL::Font infoFont(result, "Files/Lato-Bold.ttf", 14);

	const char* fireText = "FIRE";

	// Цвета для эффекта пламени
	const int flameColorCount = 10;
	LDL::Color flameColors[flameColorCount] = {
		LDL::Color(255, 255, 100),  // Ярко-желтый (центр)
		LDL::Color(255, 230, 50),   // Желтый
		LDL::Color(255, 200, 0),    // Темно-желтый
		LDL::Color(255, 170, 0),    // Оранжево-желтый
		LDL::Color(255, 140, 0),    // Светло-оранжевый
		LDL::Color(255, 100, 0),    // Оранжевый
		LDL::Color(255, 60, 0),     // Красно-оранжевый
		LDL::Color(255, 20, 0),     // Красный
		LDL::Color(200, 0, 30),     // Темно-красный
		LDL::Color(150, 0, 80)      // Бордовый (край)
	};

	// Заранее создаем текстуры для слоев пламени
	std::vector<LDL::Texture*> flameLayers;
	for (int i = 0; i < flameColorCount; i++)
	{
		rasterizer.Text(&fireFont, flameColors[i], fireText);
		flameLayers.push_back(new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels()));
	}

	// Текстура для основного текста (яркий центр)
	rasterizer.Text(&fireFont, LDL::Color(255, 255, 255), fireText);
	LDL::Texture* centerText = new LDL::Texture(result, context,
		rasterizer.GetPixelFormat(), rasterizer.GetSize(),
		rasterizer.GetPixels());

	// Текстура для подсказки
	rasterizer.Text(&infoFont, LDL::Color(200, 200, 200),
		"Fire Text Effect - Press ESC to exit");
	LDL::Texture* infoText = new LDL::Texture(result, context,
		rasterizer.GetPixelFormat(), rasterizer.GetSize(),
		rasterizer.GetPixels());

	// Цвета для искр
	const int sparkColorCount = 5;
	LDL::Color sparkColors[sparkColorCount] = {
		LDL::Color(255, 255, 150),  // Ярко-желтый
		LDL::Color(255, 220, 50),   // Желтый
		LDL::Color(255, 150, 0),    // Оранжевый
		LDL::Color(255, 50, 0),     // Красно-оранжевый
		LDL::Color(255, 0, 0)       // Красный
	};

	// Частицы-искры (увеличено до 500)
	std::vector<Spark> sparks;
	const int maxSparks = 500;

	// Позиция текста
	int textX = 100;
	int textY = 200;
	int textWidth = 600;
	int textHeight = 80;

	timer.Start();
	float currentTime = 0.0f;
	float lastTime = 0.0f;

	while (window.IsRunning() && result.IsOk())
	{
		currentTime = (float)timer.GetElapsed();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		while (window.GetEvent(event))
		{
			if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape))
			{
				window.StopEvent();
			}
			else if (event.Type == LDL_EventIsResize)
			{
				textX = (window.GetSize().x - textWidth) / 2;
				textY = (window.GetSize().y - textHeight) / 2;
			}
		}

		// Создание новых искр (увеличено количество)
		if ((int)sparks.size() < maxSparks)
		{
			int sparksToCreate = randomRange(8, 20);
			for (int i = 0; i < sparksToCreate; i++)
			{
				Spark spark;
				// Искры появляются по всей площади текста и вокруг
				spark.x = (float)(textX + randomRange(-20, textWidth + 20));
				spark.y = (float)(textY + randomRange(-10, textHeight + 10));
				spark.vx = (randomFloat() - 0.5f) * 120.0f;
				spark.vy = -(randomFloat() * 150.0f + 80.0f);
				spark.life = randomFloat() * 2.0f + 0.5f;
				spark.maxLife = spark.life;
				spark.colorIndex = rand() % sparkColorCount;
				sparks.push_back(spark);
			}
		}

		// Обновление искр
		for (size_t i = 0; i < sparks.size(); i++)
		{
			sparks[i].x += sparks[i].vx * deltaTime;
			sparks[i].y += sparks[i].vy * deltaTime;
			sparks[i].vy += 80.0f * deltaTime; // Гравитация
			sparks[i].vx += (randomFloat() - 0.5f) * 30.0f * deltaTime; // Случайное дрожание
			sparks[i].life -= deltaTime;
		}

		// Удаление мертвых искр
		for (int i = (int)sparks.size() - 1; i >= 0; i--)
		{
			if (sparks[i].life <= 0)
			{
				sparks.erase(sparks.begin() + i);
			}
		}

		render.Begin();

		// Темный фон
		render.SetColor(LDL::Color(10, 5, 15));
		render.Clear();

		// Отрисовка слоев пламени (снизу вверх, от темного к светлому)
		for (int i = flameColorCount - 1; i >= 0; i--)
		{
			// Каждый слой колеблется с разной амплитудой
			float offsetY = sin(currentTime * 8.0f + i * 1.5f) * (float)(i + 1) * 2.0f;
			float offsetX = cos(currentTime * 6.0f + i * 1.2f) * (float)(i + 1) * 0.8f;

			render.Draw(flameLayers[i],
				LDL::Vec2i(textX + (int)offsetX, textY + (int)offsetY));
		}

		// Яркий центр (белый текст)
		float centerOffsetY = sin(currentTime * 8.0f) * 1.5f;
		render.Draw(centerText,
			LDL::Vec2i(textX, textY + (int)centerOffsetY));

		// Отрисовка искр
		for (size_t i = 0; i < sparks.size(); i++)
		{
			float lifeRatio = sparks[i].life / sparks[i].maxLife;

			// Размер зависит от жизни и позиции
			int size = (int)(lifeRatio * 4) + 1;
			if (size > 5) size = 5;

			// Мерцание
			float flicker = 0.6f + randomFloat() * 0.4f;

			LDL::Color sparkColor(
				(unsigned char)(sparkColors[sparks[i].colorIndex].r * lifeRatio * flicker),
				(unsigned char)(sparkColors[sparks[i].colorIndex].g * lifeRatio * flicker),
				(unsigned char)(sparkColors[sparks[i].colorIndex].b * lifeRatio * flicker * 0.5f)
			);

			render.SetColor(sparkColor);

			// Рисуем искру
			int sparkX = (int)sparks[i].x;
			int sparkY = (int)sparks[i].y;

			if (size <= 2)
			{
				// Маленькая точка
				render.Fill(LDL::Vec2i(sparkX, sparkY), LDL::Vec2i(1, 1));
			}
			else
			{
				// Крестик для больших искр
				render.Fill(LDL::Vec2i(sparkX, sparkY), LDL::Vec2i(size, 1));
				render.Fill(LDL::Vec2i(sparkX, sparkY), LDL::Vec2i(1, size));
			}

			// Хвост за искрой
			if (lifeRatio > 0.2f)
			{
				float tailAlpha = lifeRatio * 0.5f;
				render.SetColor(LDL::Color(
					(unsigned char)(sparkColor.r * tailAlpha),
					(unsigned char)(sparkColor.g * tailAlpha * 0.5f),
					0
				));

				// Хвост из нескольких точек
				for (int t = 1; t <= 3; t++)
				{
					int tailX = sparkX + (int)(-sparks[i].vx * deltaTime * t * 2);
					int tailY = sparkY + (int)(-sparks[i].vy * deltaTime * t * 2);
					render.Fill(LDL::Vec2i(tailX, tailY), LDL::Vec2i(1, 1));
				}
			}
		}

		// Отражение огня на "земле" (увеличенное)
		for (int y = 0; y < 40; y++)
		{
			float alpha = (1.0f - (float)y / 40.0f) * 0.4f;
			float flicker = 0.8f + sin(currentTime * 10.0f + y * 0.5f) * 0.2f;
			render.SetColor(LDL::Color(
				(unsigned char)(255 * alpha * flicker),
				(unsigned char)(100 * alpha * flicker),
				0
			));
			render.Fill(LDL::Vec2i(textX - 20, textY + textHeight + 10 + y),
				LDL::Vec2i(textWidth + 40, 1));
		}

		// Дым сверху (увеличенный)
		for (int y = 0; y < 50; y++)
		{
			float alpha = (1.0f - (float)y / 50.0f) * 0.15f;
			float smokeOffset = sin(currentTime * 2.0f + y * 0.3f) * 15.0f;
			float smokeOffset2 = cos(currentTime * 1.5f + y * 0.4f) * 8.0f;
			render.SetColor(LDL::Color(
				(unsigned char)(80 * alpha),
				(unsigned char)(80 * alpha),
				(unsigned char)(80 * alpha)
			));
			render.Fill(LDL::Vec2i(textX + (int)smokeOffset + (int)smokeOffset2,
				textY - 50 - y), LDL::Vec2i(textWidth, 1));
		}

		// Угли на земле (новый эффект)
		for (int i = 0; i < 20; i++)
		{
			float emberX = textX + randomFloat() * textWidth;
			float emberY = textY + textHeight + randomFloat() * 30;
			float emberBright = 0.3f + randomFloat() * 0.7f;
			float emberFlicker = sin(currentTime * 15.0f + i * 2.5f) * 0.3f + 0.7f;

			render.SetColor(LDL::Color(
				(unsigned char)(255 * emberBright * emberFlicker),
				(unsigned char)(100 * emberBright * emberFlicker),
				0
			));
			render.Fill(LDL::Vec2i((int)emberX, (int)emberY), LDL::Vec2i(2, 2));
		}

		// Подсказка
		render.Draw(infoText, LDL::Vec2i(10, 10));

		// Счетчик частиц
		char sparkCountText[50];
		sprintf(sparkCountText, "Sparks: %d", (int)sparks.size());
		rasterizer.Text(&infoFont, LDL::Color(150, 150, 150), sparkCountText);
		LDL::Texture* countTexture = new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels());
		render.Draw(countTexture, LDL::Vec2i(10, 25));
		delete countTexture;

		render.End();
	}

	// Очистка памяти
	delete centerText;
	delete infoText;

	for (size_t i = 0; i < flameLayers.size(); i++)
	{
		delete flameLayers[i];
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}