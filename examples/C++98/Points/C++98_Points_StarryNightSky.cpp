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
	const int starSizes = 3;
	std::vector<std::vector<LDL::Texture*> > starTextures;
	for (int c = 0; c < starColorCount; c++)
	{
		std::vector<LDL::Texture*> sizeTextures;
		for (int s = 1; s <= starSizes; s++)
		{
			char starChar[2] = { '*', '\0' };
			LDL::Font starFont(result, "Files/Lato-Bold.ttf", 6 + s * 2);
			rasterizer.Text(&starFont, starColors[c], starChar);
			sizeTextures.push_back(new LDL::Texture(result, context,
				rasterizer.GetPixelFormat(), rasterizer.GetSize(),
				rasterizer.GetPixels()));
		}
		starTextures.push_back(sizeTextures);
	}

	// Текстуры для метеоров
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
	const int maxStars = 400;
	std::vector<Star> stars;

	for (int i = 0; i < maxStars; i++)
	{
		Star star;
		star.x = randomFloat() * windowWidth;
		star.y = randomFloat() * windowHeight;
		star.size = randomFloat() * 2.5f + 0.5f;
		star.twinkleSpeed = randomFloat() * 3.0f + 1.0f;
		star.twinkleOffset = randomFloat() * 6.28f;
		star.brightness = randomFloat() * 0.7f + 0.3f;
		star.colorIndex = rand() % starColorCount;
		stars.push_back(star);
	}

	// Создаем созвездия
	const int maxConstellations = 12;
	std::vector<Constellation> constellations;

	for (int i = 0; i < maxConstellations; i++)
	{
		Constellation cons;
		cons.star1Index = rand() % maxStars;
		cons.star2Index = rand() % maxStars;

		float dx = stars[cons.star1Index].x - stars[cons.star2Index].x;
		float dy = stars[cons.star1Index].y - stars[cons.star2Index].y;
		float dist = sqrtf(dx * dx + dy * dy);

		if (dist < 150.0f)
		{
			cons.brightness = randomFloat() * 0.4f + 0.2f;
			cons.pulseSpeed = randomFloat() * 1.0f + 0.5f;
			constellations.push_back(cons);
		}
	}

	// Метеоры
	std::vector<Meteor> meteors;
	const int maxMeteors = 5;

	// Используем LDL::Ticks
	unsigned int startTicks = LDL::Ticks();
	unsigned int lastTicks = startTicks;
	unsigned int lastMeteorTicks = startTicks;

	while (window.IsRunning() && result.IsOk())
	{
		unsigned int currentTicks = LDL::Ticks();
		float deltaTime = (currentTicks - lastTicks) / 1000.0f;
		float currentTime = (currentTicks - startTicks) / 1000.0f;
		lastTicks = currentTicks;

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

				for (size_t i = 0; i < stars.size(); i++)
				{
					stars[i].x = (stars[i].x / windowWidth) * newWidth;
					stars[i].y = (stars[i].y / windowHeight) * newHeight;
				}

				windowWidth = newWidth;
				windowHeight = newHeight;
			}
		}

		// Создание метеоров
		if (currentTicks - lastMeteorTicks > (unsigned int)(randomRange(2000, 5000)))
		{
			if ((int)meteors.size() < maxMeteors)
			{
				Meteor meteor;
				int side = rand() % 4;
				switch (side)
				{
				case 0:
					meteor.x = randomFloat() * windowWidth;
					meteor.y = -10.0f;
					meteor.vx = (randomFloat() - 0.5f) * 200.0f;
					meteor.vy = randomFloat() * 300.0f + 100.0f;
					break;
				case 1:
					meteor.x = windowWidth + 10.0f;
					meteor.y = randomFloat() * windowHeight;
					meteor.vx = -(randomFloat() * 200.0f + 100.0f);
					meteor.vy = (randomFloat() - 0.3f) * 100.0f;
					break;
				case 2:
					meteor.x = -10.0f;
					meteor.y = randomFloat() * windowHeight;
					meteor.vx = randomFloat() * 200.0f + 100.0f;
					meteor.vy = (randomFloat() - 0.3f) * 100.0f;
					break;
				case 3:
					meteor.x = randomFloat() * windowWidth;
					meteor.y = windowHeight + 10.0f;
					meteor.vx = (randomFloat() - 0.5f) * 200.0f;
					meteor.vy = -(randomFloat() * 300.0f + 100.0f);
					break;
				}

				meteor.life = randomFloat() * 1.5f + 0.5f;
				meteor.maxLife = meteor.life;
				meteor.colorIndex = rand() % meteorColorCount;
				meteors.push_back(meteor);
			}
			lastMeteorTicks = currentTicks;
		}

		// Обновление метеоров
		for (size_t i = 0; i < meteors.size(); i++)
		{
			meteors[i].x += meteors[i].vx * deltaTime;
			meteors[i].y += meteors[i].vy * deltaTime;
			meteors[i].life -= deltaTime;
		}

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

		// Ночное небо
		render.SetColor(LDL::Color(3, 3, 15));
		render.Clear();

		// Градиент неба
		for (int y = 0; y < windowHeight; y++)
		{
			float t = (float)y / windowHeight;
			LDL::Color skyColor(
				(unsigned char)(3 + t * 10),
				(unsigned char)(3 + t * 8),
				(unsigned char)(15 + t * 25)
			);
			render.SetColor(skyColor);
			render.Fill(LDL::Vec2i(0, y), LDL::Vec2i(windowWidth, 1));
		}

		// Туманности (яркие!)
		for (int i = 0; i < 3; i++)
		{
			float nx = windowWidth * (0.3f + i * 0.2f) + sin(currentTime * 0.1f + i) * 50.0f;
			float ny = windowHeight * (0.3f + i * 0.15f) + cos(currentTime * 0.15f + i) * 30.0f;

			// Цвета туманностей
			LDL::Color nebulaMainColors[3] = {
				LDL::Color(80, 40, 180),   // Фиолетовая
				LDL::Color(40, 120, 200),  // Синяя
				LDL::Color(180, 60, 120)   // Розовая
			};

			for (int dy = -40; dy <= 40; dy++)
			{
				for (int dx = -40; dx <= 40; dx++)
				{
					float dist = sqrtf((float)(dx * dx + dy * dy));
					if (dist < 40.0f)
					{
						float alpha = (1.0f - dist / 40.0f) * 0.15f;
						int px = (int)nx + dx;
						int py = (int)ny + dy;

						if (px >= 0 && px < windowWidth && py >= 0 && py < windowHeight)
						{
							render.SetColor(LDL::Color(
								(unsigned char)(3 + nebulaMainColors[i].r * alpha),
								(unsigned char)(3 + nebulaMainColors[i].g * alpha),
								(unsigned char)(15 + nebulaMainColors[i].b * alpha)
							));
							render.Fill(LDL::Vec2i(px, py), LDL::Vec2i(1, 1));
						}
					}
				}
			}
		}

		// Отрисовка созвездий
		for (size_t i = 0; i < constellations.size(); i++)
		{
			float pulse = sin(currentTime * constellations[i].pulseSpeed) * 0.5f + 0.5f;
			float alpha = constellations[i].brightness * pulse;

			int x1 = (int)stars[constellations[i].star1Index].x;
			int y1 = (int)stars[constellations[i].star1Index].y;
			int x2 = (int)stars[constellations[i].star2Index].x;
			int y2 = (int)stars[constellations[i].star2Index].y;

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
						(unsigned char)(80 * alpha),
						(unsigned char)(100 * alpha),
						(unsigned char)(160 * alpha)
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

			if (finalBrightness > 0.5f)
			{
				render.Draw(starTextures[stars[i].colorIndex][sizeIndex],
					LDL::Vec2i((int)stars[i].x, (int)stars[i].y));

				// Крест свечения
				if (finalBrightness > 0.75f)
				{
					float glowAlpha = (finalBrightness - 0.75f) * 4.0f;
					LDL::Color glowColor(
						(unsigned char)(starColors[stars[i].colorIndex].r * glowAlpha * 0.6f),
						(unsigned char)(starColors[stars[i].colorIndex].g * glowAlpha * 0.6f),
						(unsigned char)(starColors[stars[i].colorIndex].b * glowAlpha * 0.6f)
					);

					render.SetColor(glowColor);
					render.Fill(LDL::Vec2i((int)stars[i].x - 4, (int)stars[i].y), LDL::Vec2i(9, 1));
					render.Fill(LDL::Vec2i((int)stars[i].x, (int)stars[i].y - 4), LDL::Vec2i(1, 9));
				}
			}
			else
			{
				LDL::Color dimColor(
					(unsigned char)(starColors[stars[i].colorIndex].r * finalBrightness),
					(unsigned char)(starColors[stars[i].colorIndex].g * finalBrightness),
					(unsigned char)(starColors[stars[i].colorIndex].b * finalBrightness)
				);
				render.SetColor(dimColor);
				render.Fill(LDL::Vec2i((int)stars[i].x, (int)stars[i].y), LDL::Vec2i(1, 1));
			}
		}

		// Отрисовка метеоров
		for (size_t i = 0; i < meteors.size(); i++)
		{
			float lifeRatio = meteors[i].life / meteors[i].maxLife;

			// Хвост метеора
			int tailLength = (int)(25 * lifeRatio);
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

			// Голова метеора
			render.Draw(meteorTextures[meteors[i].colorIndex],
				LDL::Vec2i((int)meteors[i].x, (int)meteors[i].y));
		}

		// Подсказка
		render.Draw(infoText, LDL::Vec2i(10, 10));

		// Статистика
		char statsText[100];
		sprintf(statsText, "Stars: %d | Meteors: %d | Constellations: %d",
			(int)stars.size(), (int)meteors.size(), (int)constellations.size());
		rasterizer.Text(&infoFont, LDL::Color(120, 120, 180), statsText);
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