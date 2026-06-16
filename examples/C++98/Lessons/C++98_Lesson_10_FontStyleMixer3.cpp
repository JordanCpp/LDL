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
		"LDL C++98 - Text Equalizer", LDL::Window::Resized);
	LDL::Render2D render(result, context, window);
	LDL::Rasterizer rasterizer(result);
	SimpleTimer timer;

	// Шрифты
	LDL::Font eqFont(result, "Files/Lato-Bold.ttf", 64);
	LDL::Font smallFont(result, "Files/Lato-Bold.ttf", 20);
	LDL::Font infoFont(result, "Files/Lato-Bold.ttf", 14);

	const char* eqText = "EQUALIZER";
	int textLength = strlen(eqText);

	// Цвета для букв (от зеленого к красному через желтый)
	const int colorSteps = 20;
	std::vector<LDL::Color> eqColors;
	for (int i = 0; i < colorSteps; i++)
	{
		float t = (float)i / (float)(colorSteps - 1);
		unsigned char r, g, b;

		if (t < 0.5f)
		{
			// Зеленый -> Желтый
			float localT = t * 2.0f;
			r = (unsigned char)(localT * 255);
			g = 255;
			b = (unsigned char)((1.0f - localT) * 255);
		}
		else
		{
			// Желтый -> Красный
			float localT = (t - 0.5f) * 2.0f;
			r = 255;
			g = (unsigned char)((1.0f - localT) * 255);
			b = 0;
		}

		eqColors.push_back(LDL::Color(r, g, b));
	}

	// Создаем текстуры для каждой буквы во всех цветах
	std::vector<std::vector<LDL::Texture*> > letterTextures;
	for (int i = 0; i < textLength; i++)
	{
		char singleChar[2] = { eqText[i], '\0' };
		std::vector<LDL::Texture*> colorTextures;

		for (int c = 0; c < colorSteps; c++)
		{
			rasterizer.Text(&eqFont, eqColors[c], singleChar);
			colorTextures.push_back(new LDL::Texture(result, context,
				rasterizer.GetPixelFormat(), rasterizer.GetSize(),
				rasterizer.GetPixels()));
		}
		letterTextures.push_back(colorTextures);
	}

	// Текстуры для отражений (с альфа-эффектом через цвет)
	std::vector<std::vector<LDL::Texture*> > reflectionTextures;
	for (int i = 0; i < textLength; i++)
	{
		char singleChar[2] = { eqText[i], '\0' };
		std::vector<LDL::Texture*> refTextures;

		for (int c = 0; c < colorSteps; c++)
		{
			// Отражение - более тусклый цвет
			LDL::Color refColor(
				(unsigned char)(eqColors[c].r / 4),
				(unsigned char)(eqColors[c].g / 4),
				(unsigned char)(eqColors[c].b / 4)
			);
			rasterizer.Text(&eqFont, refColor, singleChar);
			refTextures.push_back(new LDL::Texture(result, context,
				rasterizer.GetPixelFormat(), rasterizer.GetSize(),
				rasterizer.GetPixels()));
		}
		reflectionTextures.push_back(refTextures);
	}

	// Текстуры для частиц
	const int particleColorsCount = 3;
	LDL::Color particleColors[particleColorsCount] = {
		LDL::Color(255, 255, 100),  // Желтый
		LDL::Color(100, 255, 100),  // Зеленый
		LDL::Color(255, 100, 100)   // Красный
	};

	std::vector<LDL::Texture*> particleTextures[particleColorsCount];
	for (int c = 0; c < particleColorsCount; c++)
	{
		for (int s = 1; s <= 3; s++)
		{
			char sizeChar[2] = { '*', '\0' };
			rasterizer.Text(&smallFont, particleColors[c], sizeChar);
			particleTextures[c].push_back(new LDL::Texture(result, context,
				rasterizer.GetPixelFormat(), rasterizer.GetSize(),
				rasterizer.GetPixels()));
		}
	}

	// Текстура для подсказки
	rasterizer.Text(&infoFont, LDL::Color(200, 200, 200),
		"Text Equalizer - Press ESC to exit");
	LDL::Texture* infoText = new LDL::Texture(result, context,
		rasterizer.GetPixelFormat(), rasterizer.GetSize(),
		rasterizer.GetPixels());

	// Частицы
	struct Particle
	{
		float x, y;
		float life;
		float maxLife;
		int colorIndex;
	};

	std::vector<Particle> particles;
	const int maxParticles = 50;

	// Параметры анимации
	float bassIntensity = 0.0f;
	float trebleIntensity = 0.0f;

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
		}

		// Симуляция музыки (басы и высокие частоты)
		bassIntensity = sin(currentTime * 1.5f) * 0.5f + 0.5f;
		trebleIntensity = sin(currentTime * 4.0f) * cos(currentTime * 2.5f) * 0.5f + 0.5f;

		// Создание частиц на пиках
		if (trebleIntensity > 0.8f && (int)particles.size() < maxParticles)
		{
			for (int i = 0; i < 3; i++)
			{
				Particle p;
				p.x = 100.0f + randomFloat() * 600.0f;
				p.y = 350.0f - randomFloat() * 200.0f;
				p.life = randomFloat() * 0.5f + 0.2f;
				p.maxLife = p.life;
				p.colorIndex = rand() % particleColorsCount;
				particles.push_back(p);
			}
		}

		// Обновление частиц
		for (size_t i = 0; i < particles.size(); i++)
		{
			particles[i].y -= 30.0f * deltaTime;
			particles[i].x += (randomFloat() - 0.5f) * 20.0f * deltaTime;
			particles[i].life -= deltaTime;
		}

		// Удаление мертвых частиц
		for (int i = (int)particles.size() - 1; i >= 0; i--)
		{
			if (particles[i].life <= 0)
			{
				particles.erase(particles.begin() + i);
			}
		}

		render.Begin();

		// Темный фон
		render.SetColor(LDL::Color(10, 10, 20));
		render.Clear();

		// Сетка фона (как звуковая студия)
		for (int y = 0; y < 600; y += 30)
		{
			render.SetColor(LDL::Color(20, 20, 35));
			render.Fill(LDL::Vec2i(0, y), LDL::Vec2i(800, 1));
		}
		for (int x = 0; x < 800; x += 30)
		{
			render.SetColor(LDL::Color(20, 20, 35));
			render.Fill(LDL::Vec2i(x, 0), LDL::Vec2i(1, 600));
		}

		// Отрисовка букв эквалайзера
		int baseY = 350;
		int letterSpacing = 80;
		int startX = (800 - (textLength * letterSpacing)) / 2 + 40;

		for (int i = 0; i < textLength; i++)
		{
			// Разная частота для каждой буквы
			float frequency = 1.0f + i * 0.4f;
			float amplitude = 40.0f + i * 15.0f;

			// Комбинация басов и высоких частот
			float height1 = sin(currentTime * frequency * 3.0f + i * 0.7f) * amplitude * bassIntensity;
			float height2 = cos(currentTime * frequency * 2.5f + i) * amplitude * 0.5f * trebleIntensity;
			float finalHeight = fabsf(height1 + height2);

			// Выбор цвета на основе высоты
			float colorRatio = finalHeight / (amplitude * 1.5f);
			if (colorRatio > 1.0f) colorRatio = 1.0f;
			int colorIndex = (int)(colorRatio * (colorSteps - 1));

			int x = startX + i * letterSpacing;
			int y = baseY - (int)finalHeight;

			// Основная буква
			render.Draw(letterTextures[i][colorIndex], LDL::Vec2i(x, y));

			// Отражение внизу
			if (finalHeight > 5.0f)
			{
				int reflectionY = baseY + (int)finalHeight;
				render.Draw(reflectionTextures[i][colorIndex], LDL::Vec2i(x, reflectionY));
			}

			// Столбик под буквой
			int barWidth = 4;
			int barX = x + 30;

			for (int barY = baseY; barY > y + 60; barY--)
			{
				float barT = (float)(baseY - barY) / (float)(baseY - y - 60);
				int barColorIdx = (int)(barT * (colorSteps - 1));
				if (barColorIdx >= colorSteps) barColorIdx = colorSteps - 1;

				render.SetColor(LDL::Color(
					(unsigned char)(eqColors[barColorIdx].r / 2),
					(unsigned char)(eqColors[barColorIdx].g / 2),
					(unsigned char)(eqColors[barColorIdx].b / 2)
				));
				render.Fill(LDL::Vec2i(barX, barY), LDL::Vec2i(barWidth, 1));
			}

			// Индикатор частоты (маленькая полоска над буквой)
			float indicatorHeight = trebleIntensity * 20.0f;
			render.SetColor(eqColors[colorIndex]);
			render.Fill(LDL::Vec2i(x + 25, y - 10 - (int)indicatorHeight),
				LDL::Vec2i(10, (int)indicatorHeight));
		}

		// Отрисовка частиц
		for (size_t i = 0; i < particles.size(); i++)
		{
			float lifeRatio = particles[i].life / particles[i].maxLife;
			float flicker = 0.5f + randomFloat() * 0.5f;

			int size = (int)(lifeRatio * 2) + 1;
			if (size > 3) size = 3;

			LDL::Color pColor(
				(unsigned char)(particleColors[particles[i].colorIndex].r * lifeRatio * flicker),
				(unsigned char)(particleColors[particles[i].colorIndex].g * lifeRatio * flicker),
				(unsigned char)(particleColors[particles[i].colorIndex].b * lifeRatio * flicker)
			);

			render.SetColor(pColor);
			render.Fill(LDL::Vec2i((int)particles[i].x, (int)particles[i].y),
				LDL::Vec2i(size, size));
		}

		// Линия "земли"
		render.SetColor(LDL::Color(50, 50, 80));
		render.Fill(LDL::Vec2i(0, baseY), LDL::Vec2i(800, 2));

		// Индикатор басов слева
		for (int y = 0; y < 200; y++)
		{
			float bassLevel = bassIntensity * 200.0f;
			render.SetColor(LDL::Color(
				(unsigned char)(y < bassLevel ? 100 : 20),
				0,
				(unsigned char)(y < bassLevel ? 255 : 20)
			));
			render.Fill(LDL::Vec2i(30, 350 - y), LDL::Vec2i(15, 1));
		}

		rasterizer.Text(&infoFont, LDL::Color(100, 100, 255), "BASS");
		LDL::Texture* bassLabel = new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels());
		render.Draw(bassLabel, LDL::Vec2i(22, 355));
		delete bassLabel;

		// Индикатор высоких частот справа
		for (int y = 0; y < 200; y++)
		{
			float trebleLevel = trebleIntensity * 200.0f;
			render.SetColor(LDL::Color(
				(unsigned char)(y < trebleLevel ? 255 : 20),
				(unsigned char)(y < trebleLevel ? 100 : 20),
				0
			));
			render.Fill(LDL::Vec2i(755, 350 - y), LDL::Vec2i(15, 1));
		}

		rasterizer.Text(&infoFont, LDL::Color(255, 100, 0), "TREBLE");
		LDL::Texture* trebleLabel = new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels());
		render.Draw(trebleLabel, LDL::Vec2i(745, 355));
		delete trebleLabel;

		// Подсказка
		render.Draw(infoText, LDL::Vec2i(10, 10));

		render.End();
	}

	// Очистка памяти
	delete infoText;

	for (size_t i = 0; i < letterTextures.size(); i++)
	{
		for (size_t c = 0; c < letterTextures[i].size(); c++)
		{
			delete letterTextures[i][c];
			delete reflectionTextures[i][c];
		}
	}

	for (int c = 0; c < particleColorsCount; c++)
	{
		for (size_t s = 0; s < particleTextures[c].size(); s++)
		{
			delete particleTextures[c][s];
		}
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}