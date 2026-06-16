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

struct Star
{
	float x, y;
	float size;
	float twinkleSpeed;
	float twinkleOffset;
	float brightness;
	int colorIndex;
};

struct Meteor
{
	float x, y;
	float vx, vy;
	float life;
	float maxLife;
	float size;
	int colorIndex;
};

struct Constellation
{
	int star1Index;
	int star2Index;
	float brightness;
	float pulseSpeed;
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
		"LDL C++98 - Starry Night Sky", LDL::Window::Resized);
	LDL::Render2D render(result, context, window);
	LDL::Rasterizer rasterizer(result);
	SimpleTimer timer;

	// Шрифт для подсказок
	LDL::Font infoFont(result, "Files/Lato-Bold.ttf", 14);

	// Текстура для подсказки
	rasterizer.Text(&infoFont, LDL::Color(200, 200, 200),
		"Starry Night Sky - Press ESC to exit");
	LDL::Texture* infoText = new LDL::Texture(result, context,
		rasterizer.GetPixelFormat(), rasterizer.GetSize(),
		rasterizer.GetPixels());

	// Цвета звезд
	const int starColorCount = 7;
	LDL::Color starColors[starColorCount] = {
		LDL::Color(255, 255, 255),  // Белый
		LDL::Color(255, 250, 240),  // Теплый белый
		LDL::Color(200, 220, 255),  // Голубоватый
		LDL::Color(255, 240, 200),  // Желтоватый
		LDL::Color(255, 200, 150),  // Оранжевый
		LDL::Color(180, 200, 255),  // Синий гигант
		LDL::Color(255, 180, 180)   // Красный карлик
	};

	// Цвета метеоров
	const int meteorColorCount = 4;
	LDL::Color meteorColors[meteorColorCount] = {
		LDL::Color(255, 255, 255),  // Белый
		LDL::Color(255, 255, 200),  // Желтоватый
		LDL::Color(200, 220, 255),  // Голубой
		LDL::Color(255, 200, 150)   // Оранжевый
	};

	// Создаем текстуры для звезд разного размера и цвета
	const int starSizes = 4; // 1x1, 2x2, 3x3, 4x4

	std::vector<std::vector<LDL::Texture*> > starTextures;
	for (int c = 0; c < starColorCount; c++)
	{
		std::vector<LDL::Texture*> sizeTextures;
		for (int s = 1; s <= starSizes; s++)
		{
			// Создаем текстуру-точку нужного размера
			// Используем символ '*' или просто создаем маленький прямоугольник
			char starChar[2] = { '*', '\0' };

			LDL::Font starFont(result, "Files/Lato-Bold.ttf", 6 + s * 2);
			rasterizer.Text(&starFont, starColors[c], starChar);
			sizeTextures.push_back(new LDL::Texture(result, context,
				rasterizer.GetPixelFormat(), rasterizer.GetSize(),
				rasterizer.GetPixels()));
		}
		starTextures.push_back(sizeTextures);
	}

	// Текстуры для метеоров (яркие точки с хвостом)
	std::vector<LDL::Texture*> meteorTextures;
	for (int c = 0; c < meteorColorCount; c++)
	{
		rasterizer.Text(&infoFont, meteorColors[c], "*");
		meteorTextures.push_back(new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels()));
	}

	int windowWidth = 800;
	int windowHeight = 600;

	// Создаем звезды
	const int maxStars = 500;
	std::vector<Star> stars;

	for (int i = 0; i < maxStars; i++)
	{
		Star star;
		star.x = randomFloat() * windowWidth;
		star.y = randomFloat() * windowHeight;
		star.size = randomFloat() * 3.0f + 1.0f;
		star.twinkleSpeed = randomFloat() * 3.0f + 1.0f;
		star.twinkleOffset = randomFloat() * 6.28f;
		star.brightness = randomFloat() * 0.7f + 0.3f;
		star.colorIndex = rand() % starColorCount;
		stars.push_back(star);
	}

	// Создаем созвездия (соединения между звездами)
	const int maxConstellations = 15;
	std::vector<Constellation> constellations;

	for (int i = 0; i < maxConstellations; i++)
	{
		Constellation cons;
		cons.star1Index = rand() % maxStars;
		cons.star2Index = rand() % maxStars;

		// Проверяем, чтобы звезды были не слишком далеко друг от друга
		float dx = stars[cons.star1Index].x - stars[cons.star2Index].x;
		float dy = stars[cons.star1Index].y - stars[cons.star2Index].y;
		float dist = sqrtf(dx * dx + dy * dy);

		if (dist < 150.0f)
		{
			cons.brightness = randomFloat() * 0.3f + 0.1f;
			cons.pulseSpeed = randomFloat() * 1.0f + 0.5f;
			constellations.push_back(cons);
		}
	}

	// Метеоры
	std::vector<Meteor> meteors;
	const int maxMeteors = 5;

	timer.Start();
	float currentTime = 0.0f;
	float lastTime = 0.0f;
	float lastMeteorTime = 0.0f;

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
				int newWidth = window.GetSize().x;
				int newHeight = window.GetSize().y;

				// Перемещаем звезды пропорционально новому размеру
				for (size_t i = 0; i < stars.size(); i++)
				{
					stars[i].x = (stars[i].x / windowWidth) * newWidth;
					stars[i].y = (stars[i].y / windowHeight) * newHeight;
				}

				windowWidth = newWidth;
				windowHeight = newHeight;
			}
		}

		// Создание метеоров (каждые 2-5 секунд)
		if (currentTime - lastMeteorTime > randomFloat() * 3.0f + 2.0f)
		{
			if ((int)meteors.size() < maxMeteors)
			{
				Meteor meteor;
				// Метеор летит с одной стороны экрана
				int side = rand() % 4;
				switch (side)
				{
				case 0: // Сверху
					meteor.x = randomFloat() * windowWidth;
					meteor.y = -10.0f;
					meteor.vx = (randomFloat() - 0.5f) * 200.0f;
					meteor.vy = randomFloat() * 300.0f + 100.0f;
					break;
				case 1: // Справа
					meteor.x = windowWidth + 10.0f;
					meteor.y = randomFloat() * windowHeight;
					meteor.vx = -(randomFloat() * 200.0f + 100.0f);
					meteor.vy = (randomFloat() - 0.3f) * 100.0f;
					break;
				case 2: // Слева
					meteor.x = -10.0f;
					meteor.y = randomFloat() * windowHeight;
					meteor.vx = randomFloat() * 200.0f + 100.0f;
					meteor.vy = (randomFloat() - 0.3f) * 100.0f;
					break;
				case 3: // Снизу
					meteor.x = randomFloat() * windowWidth;
					meteor.y = windowHeight + 10.0f;
					meteor.vx = (randomFloat() - 0.5f) * 200.0f;
					meteor.vy = -(randomFloat() * 300.0f + 100.0f);
					break;
				}

				meteor.life = randomFloat() * 1.5f + 0.5f;
				meteor.maxLife = meteor.life;
				meteor.size = randomFloat() * 2.0f + 1.0f;
				meteor.colorIndex = rand() % meteorColorCount;
				meteors.push_back(meteor);
			}
			lastMeteorTime = currentTime;
		}

		// Обновление метеоров
		for (size_t i = 0; i < meteors.size(); i++)
		{
			meteors[i].x += meteors[i].vx * deltaTime;
			meteors[i].y += meteors[i].vy * deltaTime;
			meteors[i].life -= deltaTime;
		}

		// Удаление мертвых метеоров
		for (int i = (int)meteors.size() - 1; i >= 0; i--)
		{
			if (meteors[i].life <= 0 ||
				meteors[i].x < -50 || meteors[i].x > windowWidth + 50 ||
				meteors[i].y < -50 || meteors[i].y > windowHeight + 50)
			{
				meteors.erase(meteors.begin() + i);
			}
		}

		render.Begin();

		// Глубокий темно-синий фон (ночное небо)
		render.SetColor(LDL::Color(5, 5, 20));
		render.Clear();

		// Градиент фона (более светлый у горизонта)
		for (int y = 0; y < windowHeight; y++)
		{
			float t = (float)y / windowHeight;
			LDL::Color skyColor(
				(unsigned char)(5 + t * 15),
				(unsigned char)(5 + t * 10),
				(unsigned char)(20 + t * 30)
			);
			render.SetColor(skyColor);
			render.Fill(LDL::Vec2i(0, y), LDL::Vec2i(windowWidth, 1));
		}

		// Отрисовка созвездий (линии между звездами)
		for (size_t i = 0; i < constellations.size(); i++)
		{
			float pulse = sin(currentTime * constellations[i].pulseSpeed) * 0.5f + 0.5f;
			float alpha = constellations[i].brightness * pulse;

			int x1 = (int)stars[constellations[i].star1Index].x;
			int y1 = (int)stars[constellations[i].star1Index].y;
			int x2 = (int)stars[constellations[i].star2Index].x;
			int y2 = (int)stars[constellations[i].star2Index].y;

			// Рисуем линию по точкам (алгоритм Брезенхэма упрощенно)
			float dist = sqrtf((float)((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
			int steps = (int)dist;
			if (steps < 1) steps = 1;

			for (int s = 0; s < steps; s++)
			{
				float t = (float)s / steps;
				int px = x1 + (int)((x2 - x1) * t);
				int py = y1 + (int)((y2 - y1) * t);

				if (px >= 0 && px < windowWidth && py >= 0 && py < windowHeight)
				{
					render.SetColor(LDL::Color(
						(unsigned char)(100 * alpha),
						(unsigned char)(120 * alpha),
						(unsigned char)(180 * alpha)
					));
					render.Fill(LDL::Vec2i(px, py), LDL::Vec2i(1, 1));
				}
			}
		}

		// Отрисовка звезд
		for (size_t i = 0; i < stars.size(); i++)
		{
			float twinkle = sin(currentTime * stars[i].twinkleSpeed + stars[i].twinkleOffset) * 0.3f + 0.7f;
			float finalBrightness = stars[i].brightness * twinkle;

			int sizeIndex = (int)stars[i].size;
			if (sizeIndex < 0) sizeIndex = 0;
			if (sizeIndex >= starSizes) sizeIndex = starSizes - 1;

			// Звезда с свечением
			if (finalBrightness > 0.6f)
			{
				// Основная точка
				render.Draw(starTextures[stars[i].colorIndex][sizeIndex],
					LDL::Vec2i((int)stars[i].x, (int)stars[i].y));

				// Крест свечения для ярких звезд
				if (finalBrightness > 0.8f)
				{
					float glowAlpha = (finalBrightness - 0.8f) * 5.0f;
					LDL::Color glowColor(
						(unsigned char)(starColors[stars[i].colorIndex].r * glowAlpha * 0.5f),
						(unsigned char)(starColors[stars[i].colorIndex].g * glowAlpha * 0.5f),
						(unsigned char)(starColors[stars[i].colorIndex].b * glowAlpha * 0.5f)
					);

					render.SetColor(glowColor);
					// Горизонтальный луч
					render.Fill(LDL::Vec2i((int)stars[i].x - 3, (int)stars[i].y), LDL::Vec2i(7, 1));
					// Вертикальный луч
					render.Fill(LDL::Vec2i((int)stars[i].x, (int)stars[i].y - 3), LDL::Vec2i(1, 7));
				}
			}
			else
			{
				// Тусклая звезда - просто точка
				LDL::Color dimColor(
					(unsigned char)(starColors[stars[i].colorIndex].r * finalBrightness),
					(unsigned char)(starColors[stars[i].colorIndex].g * finalBrightness),
					(unsigned char)(starColors[stars[i].colorIndex].b * finalBrightness)
				);
				render.SetColor(dimColor);
				render.Fill(LDL::Vec2i((int)stars[i].x, (int)stars[i].y),
					LDL::Vec2i(1, 1));
			}
		}

		// Отрисовка метеоров
		for (size_t i = 0; i < meteors.size(); i++)
		{
			float lifeRatio = meteors[i].life / meteors[i].maxLife;

			// Голова метеора (яркая точка)
			render.Draw(meteorTextures[meteors[i].colorIndex],
				LDL::Vec2i((int)meteors[i].x, (int)meteors[i].y));

			// Хвост метеора
			int tailLength = (int)(20 * lifeRatio);
			for (int t = 1; t <= tailLength; t++)
			{
				float tailAlpha = lifeRatio * (1.0f - (float)t / tailLength);
				int tailX = (int)(meteors[i].x - meteors[i].vx * deltaTime * t * 3);
				int tailY = (int)(meteors[i].y - meteors[i].vy * deltaTime * t * 3);

				if (tailX >= 0 && tailX < windowWidth && tailY >= 0 && tailY < windowHeight)
				{
					render.SetColor(LDL::Color(
						(unsigned char)(meteorColors[meteors[i].colorIndex].r * tailAlpha),
						(unsigned char)(meteorColors[meteors[i].colorIndex].g * tailAlpha),
						(unsigned char)(meteorColors[meteors[i].colorIndex].b * tailAlpha)
					));
					render.Fill(LDL::Vec2i(tailX, tailY), LDL::Vec2i(1, 1));
				}
			}
		}

		// Туманность (полупрозрачные цветные пятна)
		for (int i = 0; i < 3; i++)
		{
			float nx = windowWidth * (0.3f + i * 0.2f) + sin(currentTime * 0.1f + i) * 50.0f;
			float ny = windowHeight * (0.3f + i * 0.15f) + cos(currentTime * 0.15f + i) * 30.0f;

			for (int dy = -30; dy <= 30; dy++)
			{
				for (int dx = -30; dx <= 30; dx++)
				{
					float dist = sqrtf((float)(dx * dx + dy * dy));
					if (dist < 30.0f)
					{
						float alpha = (1.0f - dist / 30.0f) * 0.03f;
						int px = (int)nx + dx;
						int py = (int)ny + dy;

						if (px >= 0 && px < windowWidth && py >= 0 && py < windowHeight)
						{
							LDL::Color nebulaColor(
								(unsigned char)(100 * alpha + 5),
								(unsigned char)(50 * alpha + 5),
								(unsigned char)(150 * alpha + 20)
							);
							render.SetColor(nebulaColor);
							render.Fill(LDL::Vec2i(px, py), LDL::Vec2i(1, 1));
						}
					}
				}
			}
		}

		// Подсказка
		render.Draw(infoText, LDL::Vec2i(10, 10));

		// Счетчик объектов
		char statsText[100];
		sprintf(statsText, "Stars: %d | Meteors: %d | Constellations: %d",
			(int)stars.size(), (int)meteors.size(), (int)constellations.size());
		rasterizer.Text(&infoFont, LDL::Color(100, 100, 150), statsText);
		LDL::Texture* statsTexture = new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels());
		render.Draw(statsTexture, LDL::Vec2i(10, 25));
		delete statsTexture;

		render.End();
	}

	// Очистка памяти
	delete infoText;

	for (size_t c = 0; c < starTextures.size(); c++)
	{
		for (size_t s = 0; s < starTextures[c].size(); s++)
		{
			delete starTextures[c][s];
		}
	}

	for (size_t i = 0; i < meteorTextures.size(); i++)
	{
		delete meteorTextures[i];
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}