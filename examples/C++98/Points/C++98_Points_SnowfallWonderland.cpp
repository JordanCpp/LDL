/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <LDL/C++98/LDL.hpp>

struct Snowflake
{
	float x, y;
	float size;
	float speed;
	float windOffset;
	float wobbleSpeed;
	float wobbleAmount;
	float wobblePhase;
	float meltTimer;
	bool onGround;
	int groundX;
	float groundY;
};

struct Snowdrift
{
	float x;
	float height;
	float targetHeight;
	float growSpeed;
};

struct WindGust
{
	float strength;
	float duration;
	float timeLeft;
};

int randomRange(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

float randomFloat()
{
	return (float)rand() / (float)RAND_MAX;
}

void SnowflakeInit(std::vector<Snowflake>& snowflakes, int maxSnowflakes, const LDL::Vec2i& size)
{
	for (int i = 0; i < maxSnowflakes; i++)
	{
		Snowflake sf;
		sf.x = randomFloat() * size.x;
		sf.y = randomFloat() * size.y;
		sf.size = randomFloat() * 5.0f + 0.5f;
		sf.speed = 30.0f + sf.size * 20.0f; // Крупные падают быстрее
		sf.windOffset = 0;
		sf.wobbleSpeed = randomFloat() * 2.0f + 1.0f;
		sf.wobbleAmount = randomFloat() * 30.0f + 10.0f;
		sf.wobblePhase = randomFloat() * 6.28f;
		sf.meltTimer = 0;
		sf.onGround = false;
		sf.groundX = 0;
		sf.groundY = 0;
		snowflakes.push_back(sf);
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	LDL::Result result;
	LDL::Context context(result);
	LDL::Event event;
	LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL C++98 - Snowfall Wonderland", LDL::Window::Resized);
	LDL::Render2D render(result, context, window);
	LDL::Rasterizer rasterizer(result);

	// Шрифты
	LDL::Font snowFont(result, "Files/Lato-Bold.ttf", 12);
	LDL::Font infoFont(result, "Files/Lato-Bold.ttf", 14);
	LDL::Font titleFont(result, "Files/Lato-Bold.ttf", 32);

	// Текстура для подсказки
	rasterizer.Text(&infoFont, LDL::Color(200, 200, 220), "Snowfall Wonderland - Press ESC to exit | Arrows to control wind");
	LDL::Texture* infoText = new LDL::Texture(result, context, rasterizer.GetPixelFormat(), rasterizer.GetSize(), rasterizer.GetPixels());

	// Текстура заголовка
	rasterizer.Text(&titleFont, LDL::Color(220, 230, 255), "SNOWFALL");
	LDL::Texture* titleText = new LDL::Texture(result, context, rasterizer.GetPixelFormat(), rasterizer.GetSize(), rasterizer.GetPixels());

	// Цвета снежинок
	const int snowColorCount = 4;
	LDL::Color snowColors[snowColorCount] = {
		LDL::Color(255, 255, 255),  // Белый
		LDL::Color(240, 245, 255),  // Голубоватый
		LDL::Color(250, 250, 255),  // Слегка серый
		LDL::Color(230, 240, 255)   // Синеватый
	};

	// Создаем текстуры снежинок разных размеров
	const int snowflakeSizes = 6; // Разные размеры для эффекта параллакса
	std::vector<std::vector<LDL::Texture*> > snowflakeTextures;

	for (int c = 0; c < snowColorCount; c++)
	{
		std::vector<LDL::Texture*> sizeTextures;
		for (int s = 1; s <= snowflakeSizes; s++)
		{
			int fontSize = 4 + s * 2; // 6, 8, 10, 12, 14, 16
			LDL::Font sizedFont(result, "Files/Lato-Bold.ttf", fontSize);
			rasterizer.Text(&sizedFont, snowColors[c], "*");
			sizeTextures.push_back(new LDL::Texture(result, context, rasterizer.GetPixelFormat(), rasterizer.GetSize(), rasterizer.GetPixels()));
		}

		snowflakeTextures.push_back(sizeTextures);
	}

	int windowWidth = 800;
	int windowHeight = 600;

	// Снежинки
	const int maxSnowflakes = 1000;
	std::vector<Snowflake> snowflakes;
	SnowflakeInit(snowflakes, maxSnowflakes, window.GetSize());

	// Сугробы (100 сегментов земли)
	const int driftSegments = 100;
	std::vector<Snowdrift> snowdrifts;
	float segmentWidth = (float)windowWidth / driftSegments;

	for (int i = 0; i < driftSegments; i++)
	{
		Snowdrift drift;
		drift.x = i * segmentWidth;
		drift.height = randomFloat() * 20.0f + 10.0f;
		drift.targetHeight = drift.height;
		drift.growSpeed = randomFloat() * 0.5f + 0.1f;
		snowdrifts.push_back(drift);
	}

	// Ветер
	std::vector<WindGust> windGusts;
	float baseWind = 0.0f;
	float windStrength = 0.0f;

	// LDL::Ticks
	unsigned int startTicks = LDL::Ticks();
	unsigned int lastTicks = startTicks;
	unsigned int lastGustTicks = startTicks;

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
				windowWidth = window.GetSize().x;
				windowHeight = window.GetSize().y;

				// Обновляем сугробы
				segmentWidth = (float)windowWidth / driftSegments;
				for (int i = 0; i < driftSegments; i++)
				{
					snowdrifts[i].x = i * segmentWidth;
				}
			}
			else if (event.IsKeyPressed(LDL_KeyLeft))
			{
				baseWind -= 20.0f;
				if (baseWind < -100.0f) baseWind = -100.0f;
			}
			else if (event.IsKeyPressed(LDL_KeyRight))
			{
				baseWind += 20.0f;
				if (baseWind > 100.0f) baseWind = 100.0f;
			}
			else if (event.IsKeyPressed(LDL_KeyDown))
			{
				baseWind = 0.0f;
			}
		}

		// Создание порывов ветра
		if (currentTicks - lastGustTicks > (unsigned int)randomRange(3000, 8000))
		{
			WindGust gust;
			gust.strength = (randomFloat() - 0.5f) * 80.0f;
			gust.duration = randomFloat() * 2.0f + 0.5f;
			gust.timeLeft = gust.duration;
			windGusts.push_back(gust);
			lastGustTicks = currentTicks;
		}

		// Обновление порывов ветра
		windStrength = baseWind;
		for (size_t i = 0; i < windGusts.size(); i++)
		{
			windGusts[i].timeLeft -= deltaTime;
			if (windGusts[i].timeLeft > 0)
			{
				float factor = windGusts[i].timeLeft / windGusts[i].duration;
				windStrength += windGusts[i].strength * factor;
			}
		}

		// Удаление закончившихся порывов
		for (int i = (int)windGusts.size() - 1; i >= 0; i--)
		{
			if (windGusts[i].timeLeft <= 0)
			{
				windGusts.erase(windGusts.begin() + i);
			}
		}

		// Обновление снежинок
		for (size_t i = 0; i < snowflakes.size(); i++)
		{
			if (snowflakes[i].onGround)
			{
				// Снежинка на земле - медленно тает
				snowflakes[i].meltTimer += deltaTime;
				if (snowflakes[i].meltTimer > 10.0f)
				{
					// Возрождаем снежинку сверху
					snowflakes[i].x = randomFloat() * windowWidth;
					snowflakes[i].y = -10.0f;
					snowflakes[i].onGround = false;
					snowflakes[i].meltTimer = 0;
					snowflakes[i].size = randomFloat() * 5.0f + 0.5f;
					snowflakes[i].speed = 30.0f + snowflakes[i].size * 20.0f;
					snowflakes[i].wobblePhase = randomFloat() * 6.28f;
				}
			}
			else
			{
				// Падение снежинки
				snowflakes[i].y += snowflakes[i].speed * deltaTime;

				// Боковое движение от ветра
				snowflakes[i].windOffset += windStrength * deltaTime;
				snowflakes[i].x += snowflakes[i].windOffset * deltaTime;
				snowflakes[i].windOffset *= 0.99f;

				// Воблинг (покачивание)
				snowflakes[i].wobblePhase += snowflakes[i].wobbleSpeed * deltaTime;
				float wobble = sinf(snowflakes[i].wobblePhase) * snowflakes[i].wobbleAmount;
				snowflakes[i].x += wobble * deltaTime * 0.3f;

				// Зацикливание по горизонтали
				if (snowflakes[i].x > windowWidth + 20)
				{
					snowflakes[i].x = -20.0f;
				}
				else if (snowflakes[i].x < -20)
				{
					snowflakes[i].x = windowWidth + 20.0f;
				}

				// Приземление
				int groundIndex = (int)(snowflakes[i].x / segmentWidth);
				if (groundIndex < 0) groundIndex = 0;
				if (groundIndex >= driftSegments) groundIndex = driftSegments - 1;

				float groundLevel = windowHeight - 30 - snowdrifts[groundIndex].height;

				if (snowflakes[i].y >= groundLevel)
				{
					snowflakes[i].y = groundLevel;
					snowflakes[i].onGround = true;
					snowflakes[i].meltTimer = 0;
					snowflakes[i].groundX = groundIndex;
					snowflakes[i].groundY = groundLevel;

					// Увеличиваем сугроб
					snowdrifts[groundIndex].targetHeight += 0.3f;
					if (snowdrifts[groundIndex].targetHeight > 60.0f)
					{
						snowdrifts[groundIndex].targetHeight = 60.0f;
					}

					// Немного увеличиваем соседние сугробы
					if (groundIndex > 0)
					{
						snowdrifts[groundIndex - 1].targetHeight += 0.1f;
					}
					if (groundIndex < driftSegments - 1)
					{
						snowdrifts[groundIndex + 1].targetHeight += 0.1f;
					}
				}
			}
		}

		// Обновление сугробов (плавное приближение к целевой высоте)
		for (int i = 0; i < driftSegments; i++)
		{
			if (snowdrifts[i].height < snowdrifts[i].targetHeight)
			{
				snowdrifts[i].height += snowdrifts[i].growSpeed * deltaTime;
				if (snowdrifts[i].height > snowdrifts[i].targetHeight)
				{
					snowdrifts[i].height = snowdrifts[i].targetHeight;
				}
			}

			// Медленное оседание сугробов
			snowdrifts[i].targetHeight -= 0.02f * deltaTime;
			if (snowdrifts[i].targetHeight < 5.0f)
			{
				snowdrifts[i].targetHeight = 5.0f;
			}
			if (snowdrifts[i].height < snowdrifts[i].targetHeight - 0.5f)
			{
				snowdrifts[i].height = snowdrifts[i].targetHeight;
			}
		}

		render.Begin();

		// Зимнее небо (градиент)
		for (int y = 0; y < windowHeight; y++)
		{
			float t = (float)y / windowHeight;
			LDL::Color skyColor(
				(unsigned char)(30 + t * 40),
				(unsigned char)(40 + t * 50),
				(unsigned char)(70 + t * 60)
			);
			render.SetColor(skyColor);
			render.Fill(LDL::Vec2i(0, y), LDL::Vec2i(windowWidth, 1));
		}

		// Луна
		float moonX = windowWidth * 0.75f;
		float moonY = 80.0f;
		int moonRadius = 40;

		for (int dy = -moonRadius; dy <= moonRadius; dy++)
		{
			for (int dx = -moonRadius; dx <= moonRadius; dx++)
			{
				float dist = sqrtf((float)(dx * dx + dy * dy));
				if (dist < moonRadius)
				{
					float alpha = (1.0f - dist / moonRadius) * 0.8f;
					int px = (int)moonX + dx;
					int py = (int)moonY + dy;

					if (px >= 0 && px < windowWidth && py >= 0 && py < windowHeight)
					{
						render.SetColor(LDL::Color(
							(unsigned char)(200 + alpha * 55),
							(unsigned char)(200 + alpha * 55),
							(unsigned char)(220 + alpha * 35)
						));
						render.Fill(LDL::Vec2i(px, py), LDL::Vec2i(1, 1));
					}
				}
			}
		}

		// Отрисовка снежинок
		for (size_t i = 0; i < snowflakes.size(); i++)
		{
			int sizeIndex = (int)snowflakes[i].size;
			if (sizeIndex < 0) sizeIndex = 0;
			if (sizeIndex >= snowflakeSizes) sizeIndex = snowflakeSizes - 1;

			int colorIndex = (int)(snowflakes[i].size) % snowColorCount;

			if (snowflakes[i].onGround)
			{
				// Снежинка на земле (уменьшаем яркость)
				float meltRatio = 1.0f - (snowflakes[i].meltTimer / 10.0f);
				if (meltRatio < 0) meltRatio = 0;

				render.Draw(snowflakeTextures[colorIndex][sizeIndex],
					LDL::Vec2i((int)snowflakes[i].x, (int)snowflakes[i].y));
			}
			else
			{
				render.Draw(snowflakeTextures[colorIndex][sizeIndex],
					LDL::Vec2i((int)snowflakes[i].x, (int)snowflakes[i].y));
			}
		}

		// Отрисовка сугробов
		for (int i = 0; i < driftSegments; i++)
		{
			float baseY = (float)(windowHeight - 30);
			float driftHeight = snowdrifts[i].height;

			// Основной сугроб
			for (int y = 0; y < (int)driftHeight + 5; y++)
			{
				float alpha = 1.0f;
				if (y > driftHeight)
				{
					alpha = 1.0f - (y - driftHeight) / 5.0f;
				}

				int py = (int)(baseY - y);
				if (py >= 0 && py < windowHeight)
				{
					render.SetColor(LDL::Color(
						(unsigned char)(200 * alpha),
						(unsigned char)(210 * alpha),
						(unsigned char)(230 * alpha)
					));
					render.Fill(LDL::Vec2i((int)snowdrifts[i].x, py),
						LDL::Vec2i((int)segmentWidth + 1, 1));
				}
			}
		}

		// Индикатор ветра
		int windBarY = 50;
		render.SetColor(LDL::Color(100, 100, 120));
		render.Fill(LDL::Vec2i(windowWidth / 2 - 100, windBarY), LDL::Vec2i(200, 4));

		int windIndicatorX = windowWidth / 2 + (int)(windStrength * 1.5f);
		if (windIndicatorX < windowWidth / 2 - 100) windIndicatorX = windowWidth / 2 - 100;
		if (windIndicatorX > windowWidth / 2 + 100) windIndicatorX = windowWidth / 2 + 100;

		render.SetColor(LDL::Color(200, 200, 255));
		render.Fill(LDL::Vec2i(windIndicatorX - 3, windBarY - 3), LDL::Vec2i(6, 10));

		// Подсказка и статистика
		render.Draw(infoText, LDL::Vec2i(10, 10));

		char statsText[150];
		sprintf(statsText, "Snowflakes: %d | Wind: %.0f | Gusts: %d | Drift height: avg %.0f",
			(int)snowflakes.size(), windStrength, (int)windGusts.size(),
			snowdrifts[driftSegments / 2].height);
		rasterizer.Text(&infoFont, LDL::Color(180, 180, 200), statsText);
		LDL::Texture* statsTexture = new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels());
		render.Draw(statsTexture, LDL::Vec2i(10, 25));
		delete statsTexture;

		// Заголовок
		float titleAlpha = 0.3f + sinf(currentTime * 0.5f) * 0.1f;
		render.Draw(titleText, LDL::Vec2i(windowWidth / 2 - 100, windowHeight - 80));

		render.End();
	}

	// Очистка памяти
	delete infoText;
	delete titleText;

	for (size_t c = 0; c < snowflakeTextures.size(); c++)
	{
		for (size_t s = 0; s < snowflakeTextures[c].size(); s++)
		{
			delete snowflakeTextures[c][s];
		}
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}
