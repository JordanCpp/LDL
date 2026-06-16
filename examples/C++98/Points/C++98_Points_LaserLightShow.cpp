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

struct LaserBeam
{
	float x1, y1, x2, y2;
	float life;
	float maxLife;
	int colorIndex;
	float phase;
};

struct SparklePoint
{
	float x, y;
	float life;
	float maxLife;
	int colorIndex;
	int size;
};

struct LaserSource
{
	float x, y;
	float angle;
	float rotationSpeed;
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
		"LDL C++98 - Grand Laser Show", LDL::Window::Resized);
	LDL::Render2D render(result, context, window);
	LDL::Rasterizer rasterizer(result);

	// Шрифт для подсказок
	LDL::Font infoFont(result, "Files/Lato-Bold.ttf", 14);

	// ЯРКИЕ цвета лазеров (без полупрозрачности, чистые цвета)
	const int colorCount = 8;
	LDL::Color laserColors[colorCount] = {
		LDL::Color(255, 0, 0),      // Красный
		LDL::Color(0, 255, 0),      // Зеленый
		LDL::Color(0, 100, 255),    // Синий
		LDL::Color(255, 255, 0),    // Желтый
		LDL::Color(255, 0, 255),    // Пурпурный
		LDL::Color(0, 255, 255),    // Голубой
		LDL::Color(255, 128, 0),    // Оранжевый
		LDL::Color(128, 0, 255)     // Фиолетовый
	};

	int windowWidth = 800;
	int windowHeight = 600;

	// Лучи
	std::vector<LaserBeam> beams;

	// Сверкающие точки
	std::vector<SparklePoint> sparkles;

	// Источники лазеров
	std::vector<LaserSource> sources;

	// 8 источников по периметру
	for (int i = 0; i < 8; i++)
	{
		LaserSource source;
		source.angle = randomFloat() * 6.28f;
		source.rotationSpeed = (randomFloat() - 0.5f) * 3.0f;
		source.colorIndex = i % colorCount;

		float t = (float)i / 8.0f;
		if (t < 0.25f) { source.x = windowWidth * t * 4.0f; source.y = 0; }
		else if (t < 0.5f) { source.x = (float)windowWidth; source.y = windowHeight * (t - 0.25f) * 4.0f; }
		else if (t < 0.75f) { source.x = windowWidth * (1.0f - (t - 0.5f) * 4.0f); source.y = (float)windowHeight; }
		else { source.x = 0; source.y = windowHeight * (1.0f - (t - 0.75f) * 4.0f); }

		sources.push_back(source);
	}

	// 4 источника внутри
	for (int i = 0; i < 4; i++)
	{
		LaserSource source;
		source.x = windowWidth * (0.25f + i * 0.15f);
		source.y = windowHeight * 0.5f;
		source.angle = randomFloat() * 6.28f;
		source.rotationSpeed = (randomFloat() - 0.5f) * 4.0f;
		source.colorIndex = (i + 4) % colorCount;
		sources.push_back(source);
	}

	int currentMode = 0;
	float userRotation = 0;
	int mouseX = windowWidth / 2;
	int mouseY = windowHeight / 2;

	// LDL::Ticks
	unsigned int startTicks = LDL::Ticks();
	unsigned int lastTicks = startTicks;

	while (window.IsRunning() && result.IsOk())
	{
		unsigned int currentTicks = LDL::Ticks();
		float deltaTime = (currentTicks - lastTicks) / 1000.0f;
		float currentTime = (currentTicks - startTicks) / 1000.0f;
		lastTicks = currentTicks;

		if (deltaTime > 0.1f) deltaTime = 0.1f;

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

				for (size_t i = 0; i < sources.size() && i < 8; i++)
				{
					float t = (float)i / 8.0f;
					if (t < 0.25f) { sources[i].x = windowWidth * t * 4.0f; sources[i].y = 0; }
					else if (t < 0.5f) { sources[i].x = (float)windowWidth; sources[i].y = windowHeight * (t - 0.25f) * 4.0f; }
					else if (t < 0.75f) { sources[i].x = windowWidth * (1.0f - (t - 0.5f) * 4.0f); sources[i].y = (float)windowHeight; }
					else { sources[i].x = 0; sources[i].y = windowHeight * (1.0f - (t - 0.75f) * 4.0f); }
				}
			}
			else if (event.IsKeyPressed(LDL_KeySpace))
			{
				currentMode = (currentMode + 1) % 3;
				beams.clear();
				sparkles.clear();
			}
			else if (event.IsKeyPressed(LDL_KeyLeft))
			{
				userRotation -= 1.0f;
			}
			else if (event.IsKeyPressed(LDL_KeyRight))
			{
				userRotation += 1.0f;
			}
			else if (event.Type == LDL_EventIsMouseMove)
			{
				mouseX = event.u.Mouse.PosX;
				mouseX = event.u.Mouse.PosY;
			}

			else if (LDL_EventIsMousePressed(&event, LDL_MouseButtonLeft))
			{
				// Взрыв точек по клику
				for (int i = 0; i < 50; i++)
				{
					SparklePoint sp;
					sp.x = (float)mouseX + (randomFloat() - 0.5f) * 200.0f;
					sp.y = (float)mouseY + (randomFloat() - 0.5f) * 200.0f;
					sp.life = randomFloat() * 0.8f + 0.4f;
					sp.maxLife = sp.life;
					sp.colorIndex = rand() % colorCount;
					sp.size = randomRange(3, 8);
					sparkles.push_back(sp);
				}
			}
		}

		// Обновление источников
		for (size_t i = 0; i < sources.size(); i++)
		{
			sources[i].angle += sources[i].rotationSpeed * deltaTime;
			sources[i].angle += userRotation * deltaTime * 0.5f;

			int raysCount = (currentMode == 0) ? 3 : ((currentMode == 1) ? 5 : 8);

			if (beams.size() < 1000 && rand() % 100 < 40)
			{
				for (int r = 0; r < raysCount; r++)
				{
					if (beams.size() >= 1000) break;

					LaserBeam beam;
					beam.x1 = sources[i].x;
					beam.y1 = sources[i].y;

					float spreadAngle = (currentMode == 2) ? 1.2f : 0.5f;
					float beamAngle = sources[i].angle + (r - raysCount / 2) * spreadAngle;
					float beamLength = 500.0f + randomFloat() * 500.0f;

					beam.x2 = beam.x1 + cosf(beamAngle) * beamLength;
					beam.y2 = beam.y1 + sinf(beamAngle) * beamLength;
					beam.life = randomFloat() * 1.5f + 0.5f;
					beam.maxLife = beam.life;
					beam.colorIndex = (sources[i].colorIndex + r) % colorCount;
					beam.phase = randomFloat() * 6.28f;
					beams.push_back(beam);

					// Точки на луче
					for (int p = 0; p < 8; p++)
					{
						if (sparkles.size() >= 500) break;

						float t = randomFloat();
						SparklePoint sp;
						sp.x = beam.x1 + (beam.x2 - beam.x1) * t;
						sp.y = beam.y1 + (beam.y2 - beam.y1) * t;
						sp.life = randomFloat() * 0.5f + 0.2f;
						sp.maxLife = sp.life;
						sp.colorIndex = beam.colorIndex;
						sp.size = randomRange(2, 6);
						sparkles.push_back(sp);
					}
				}
			}
		}

		// Обновление лучей
		for (size_t i = 0; i < beams.size(); i++)
		{
			beams[i].life -= deltaTime;
		}

		// Обновление точек
		for (size_t i = 0; i < sparkles.size(); i++)
		{
			sparkles[i].life -= deltaTime;
		}

		// Удаление мертвых
		for (int i = (int)beams.size() - 1; i >= 0; i--)
		{
			if (beams[i].life <= 0) beams.erase(beams.begin() + i);
		}

		for (int i = (int)sparkles.size() - 1; i >= 0; i--)
		{
			if (sparkles[i].life <= 0) sparkles.erase(sparkles.begin() + i);
		}

		render.Begin();

		// ЧЕРНЫЙ фон
		render.SetColor(LDL::Color(0, 0, 0));
		render.Clear();

		// Отрисовка лучей
		for (size_t i = 0; i < beams.size(); i++)
		{
			float lifeRatio = beams[i].life / beams[i].maxLife;

			// Пропускаем почти мертвые лучи
			if (lifeRatio < 0.1f) continue;

			// ЯРКИЙ цвет луча (без альфа-смешивания)
			LDL::Color beamColor = laserColors[beams[i].colorIndex];

			int x1 = (int)beams[i].x1;
			int y1 = (int)beams[i].y1;
			int x2 = (int)beams[i].x2;
			int y2 = (int)beams[i].y2;

			float dx = (float)(x2 - x1);
			float dy = (float)(y2 - y1);
			float dist = sqrtf(dx * dx + dy * dy);
			int steps = (int)dist;
			if (steps < 1) steps = 1;

			// Толщина луча (3-5 пикселей)
			int thickness = 3;

			// Рисуем толстую линию
			for (int s = 0; s < steps; s++)
			{
				float t = (float)s / steps;
				int px = x1 + (int)(dx * t);
				int py = y1 + (int)(dy * t);

				if (px < 0 || px >= windowWidth || py < 0 || py >= windowHeight) continue;

				// Жирная линия
				render.SetColor(beamColor);
				for (int ty = -thickness; ty <= thickness; ty++)
				{
					for (int tx = -thickness; tx <= thickness; tx++)
					{
						if (tx * tx + ty * ty <= thickness * thickness)
						{
							int tpx = px + tx;
							int tpy = py + ty;

							if (tpx >= 0 && tpx < windowWidth && tpy >= 0 && tpy < windowHeight)
							{
								render.Fill(LDL::Vec2i(tpx, tpy), LDL::Vec2i(1, 1));
							}
						}
					}
				}
			}
		}

		// Отрисовка сверкающих точек (КРУПНЫХ и ЯРКИХ)
		for (size_t i = 0; i < sparkles.size(); i++)
		{
			float lifeRatio = sparkles[i].life / sparkles[i].maxLife;
			if (lifeRatio < 0.1f) continue;

			float pulse = fabsf(sinf(currentTime * 20.0f + i));

			int size = sparkles[i].size;
			if (pulse < 0.3f) size = size / 2;
			if (size < 1) size = 1;

			LDL::Color sparkColor = laserColors[sparkles[i].colorIndex];

			int sx = (int)sparkles[i].x;
			int sy = (int)sparkles[i].y;

			if (sx < 0 || sx >= windowWidth || sy < 0 || sy >= windowHeight) continue;

			// Жирный крест
			render.SetColor(sparkColor);
			render.Fill(LDL::Vec2i(sx - size, sy - 1), LDL::Vec2i(size * 2 + 1, 3));
			render.Fill(LDL::Vec2i(sx - 1, sy - size), LDL::Vec2i(3, size * 2 + 1));

			// Яркий центр
			render.SetColor(LDL::Color(255, 255, 255));
			render.Fill(LDL::Vec2i(sx - 1, sy - 1), LDL::Vec2i(3, 3));
		}

		// Отрисовка источников
		for (size_t i = 0; i < sources.size(); i++)
		{
			LDL::Color sourceColor = laserColors[sources[i].colorIndex];

			int sx = (int)sources[i].x;
			int sy = (int)sources[i].y;

			if (sx < 0 || sx >= windowWidth || sy < 0 || sy >= windowHeight) continue;

			// Большой круг
			render.SetColor(sourceColor);
			for (int dy = -8; dy <= 8; dy++)
			{
				for (int dx = -8; dx <= 8; dx++)
				{
					if (dx * dx + dy * dy <= 64)
					{
						int px = sx + dx;
						int py = sy + dy;

						if (px >= 0 && px < windowWidth && py >= 0 && py < windowHeight)
						{
							render.Fill(LDL::Vec2i(px, py), LDL::Vec2i(1, 1));
						}
					}
				}
			}

			// Белый центр
			render.SetColor(LDL::Color(255, 255, 255));
			for (int dy = -3; dy <= 3; dy++)
			{
				for (int dx = -3; dx <= 3; dx++)
				{
					if (dx * dx + dy * dy <= 9)
					{
						int px = sx + dx;
						int py = sy + dy;

						if (px >= 0 && px < windowWidth && py >= 0 && py < windowHeight)
						{
							render.Fill(LDL::Vec2i(px, py), LDL::Vec2i(1, 1));
						}
					}
				}
			}
		}

		// Статистика (создаём текстуру один раз)
		const char* modeNames[3] = { "RAY BURST", "MIRROR MAZE", "LASER STORM" };
		char statsText[100];
		sprintf(statsText, "%s | Beams: %d | Sparkles: %d",
			modeNames[currentMode], (int)beams.size(), (int)sparkles.size());
		rasterizer.Text(&infoFont, LDL::Color(255, 255, 255), statsText);
		LDL::Texture* statsTexture = new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels());
		render.Draw(statsTexture, LDL::Vec2i(10, 10));
		delete statsTexture;

		render.End();
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}
