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

struct Particle
{
	float x, y;
	float vx, vy;
	float life;
	float maxLife;
	int colorIndex;
	float gravity;
	float size;
};

struct Firework
{
	float x, y;
	float explosionTime;
	bool exploded;
	int particleCount;
	int colorIndex;
	float trail[15][2];
	int trailLength;
	float targetY;
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

// Частицы
std::vector<Particle> particles;
const int maxParticles = 5000;

// Фейерверки (МНОГО)
std::vector<Firework> fireworks;
const int maxFireworks = 30;

// Искры
std::vector<Spark> sparks;
const int maxSparks = 300;

int main()
{
	srand((unsigned int)time(NULL));

	LDL::Result result;
	LDL::Context context(result);
	LDL::Event event;
	LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600),
		"LDL C++98 - Grand Fireworks Show", LDL::Window::Resized);
	LDL::Render2D render(result, context, window);
	LDL::Rasterizer rasterizer(result);

	// Шрифты
	LDL::Font infoFont(result, "Files/Lato-Bold.ttf", 14);
	LDL::Font bigFont(result, "Files/Lato-Bold.ttf", 24);
	LDL::Font particleFont(result, "Files/Lato-Bold.ttf", 12);

	// Текстура для подсказки
	rasterizer.Text(&infoFont, LDL::Color(200, 200, 200),
		"GRAND FIREWORKS - Click to launch! Press ESC to exit");
	LDL::Texture* infoText = new LDL::Texture(result, context,
		rasterizer.GetPixelFormat(), rasterizer.GetSize(),
		rasterizer.GetPixels());

	// Яркие цвета для фейерверков
	const int colorCount = 12;
	LDL::Color fireworkColors[colorCount] = {
		LDL::Color(255, 30, 30),    // Ярко-красный
		LDL::Color(255, 120, 30),   // Оранжевый
		LDL::Color(255, 255, 30),   // Желтый
		LDL::Color(30, 255, 30),    // Зеленый
		LDL::Color(30, 150, 255),   // Синий
		LDL::Color(150, 30, 255),   // Фиолетовый
		LDL::Color(255, 30, 255),   // Пурпурный
		LDL::Color(30, 255, 255),   // Голубой
		LDL::Color(255, 200, 50),   // Золотой
		LDL::Color(255, 80, 180),   // Розовый
		LDL::Color(100, 255, 100),  // Лаймовый
		LDL::Color(255, 255, 255)   // Белый
	};

	// Создаем текстуры частиц разных размеров (КРУПНЫЕ)
	const int particleSizes = 5;
	std::vector<std::vector<LDL::Texture*> > particleTextures;

	for (int c = 0; c < colorCount; c++)
	{
		std::vector<LDL::Texture*> sizeTextures;
		for (int s = 1; s <= particleSizes; s++)
		{
			int fontSize = 6 + s * 4; // 10, 14, 18, 22, 26
			LDL::Font sizedFont(result, "Files/Lato-Bold.ttf", fontSize);
			rasterizer.Text(&sizedFont, fireworkColors[c], "*");
			sizeTextures.push_back(new LDL::Texture(result, context,
				rasterizer.GetPixelFormat(), rasterizer.GetSize(),
				rasterizer.GetPixels()));
		}
		particleTextures.push_back(sizeTextures);
	}

	// Текстуры для крупных искр
	std::vector<std::vector<LDL::Texture*> > sparkTextures;
	for (int c = 0; c < colorCount; c++)
	{
		std::vector<LDL::Texture*> sizeTextures;
		for (int s = 1; s <= 3; s++)
		{
			int fontSize = 8 + s * 3;
			LDL::Font sizedFont(result, "Files/Lato-Bold.ttf", fontSize);
			rasterizer.Text(&sizedFont, fireworkColors[c], ".");
			sizeTextures.push_back(new LDL::Texture(result, context,
				rasterizer.GetPixelFormat(), rasterizer.GetSize(),
				rasterizer.GetPixels()));
		}
		sparkTextures.push_back(sizeTextures);
	}

	int windowWidth = 800;
	int windowHeight = 600;



	// Используем LDL::Ticks
	unsigned int startTicks = LDL::Ticks();
	unsigned int lastTicks = startTicks;
	unsigned int lastLaunchTicks = startTicks;
	unsigned int lastGrandLaunchTicks = startTicks;

	bool mousePressed = false;
	int mouseX = 400;
	int mouseY = 300;

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
			}
			else if (event.Type == LDL_EventIsMouseMove)
			{
				mouseX = event.u.Mouse.PosX;
				mouseX = event.u.Mouse.PosY;
			}
			
			else if (LDL_EventIsMousePressed(&event, LDL_MouseButtonLeft))
			{
				mousePressed = true;
				mouseX = event.u.Mouse.PosX;
				mouseX = event.u.Mouse.PosY;
			}
		}

		// Частый автозапуск фейерверков
		if (currentTicks - lastLaunchTicks > (unsigned int)randomRange(400, 1000))
		{
			if ((int)fireworks.size() < maxFireworks)
			{
				Firework fw;
				fw.x = randomFloat() * windowWidth;
				fw.y = windowHeight + 20.0f;
				fw.targetY = randomFloat() * windowHeight * 0.6f + windowHeight * 0.1f;
				fw.explosionTime = (fw.y - fw.targetY) / (300.0f + randomFloat() * 200.0f);
				fw.exploded = false;
				fw.particleCount = randomRange(150, 300);
				fw.colorIndex = rand() % colorCount;
				fw.trailLength = 0;
				fireworks.push_back(fw);
			}
			lastLaunchTicks = currentTicks;
		}

		// Грандиозный залп каждые 5-8 секунд
		if (currentTicks - lastGrandLaunchTicks > (unsigned int)randomRange(5000, 8000))
		{
			// Запускаем сразу несколько фейерверков
			int salvoCount = randomRange(5, 10);
			for (int s = 0; s < salvoCount; s++)
			{
				if ((int)fireworks.size() < maxFireworks)
				{
					Firework fw;
					fw.x = windowWidth * (0.2f + randomFloat() * 0.6f);
					fw.y = windowHeight + 20.0f;
					fw.targetY = randomFloat() * windowHeight * 0.5f + windowHeight * 0.1f;
					fw.explosionTime = (fw.y - fw.targetY) / (300.0f + randomFloat() * 200.0f);
					fw.exploded = false;
					fw.particleCount = randomRange(200, 400);
					fw.colorIndex = rand() % colorCount;
					fw.trailLength = 0;
					fireworks.push_back(fw);
				}
			}
			lastGrandLaunchTicks = currentTicks;
		}

		// Запуск по клику (несколько сразу)
		if (mousePressed)
		{
			int clickCount = randomRange(2, 5);
			for (int c = 0; c < clickCount; c++)
			{
				if ((int)fireworks.size() < maxFireworks)
				{
					Firework fw;
					fw.x = mouseX + randomRange(-50, 50);
					fw.y = windowHeight + 20.0f;
					fw.targetY = mouseY + randomRange(-30, 30);
					fw.explosionTime = (fw.y - fw.targetY) / (350.0f + randomFloat() * 250.0f);
					fw.exploded = false;
					fw.particleCount = randomRange(200, 350);
					fw.colorIndex = rand() % colorCount;
					fw.trailLength = 0;
					fireworks.push_back(fw);
				}
			}
			mousePressed = false;
		}

		// Обновление фейерверков
		for (size_t i = 0; i < fireworks.size(); i++)
		{
			if (!fireworks[i].exploded)
			{
				fireworks[i].explosionTime -= deltaTime;

				float speed = 350.0f + randomFloat() * 100.0f;
				fireworks[i].y -= speed * deltaTime;
				fireworks[i].x += sinf(currentTime * 10.0f + i) * 10.0f * deltaTime;

				// Сохраняем трек
				if (fireworks[i].trailLength < 15)
				{
					fireworks[i].trail[fireworks[i].trailLength][0] = fireworks[i].x;
					fireworks[i].trail[fireworks[i].trailLength][1] = fireworks[i].y;
					fireworks[i].trailLength++;
				}
				else
				{
					for (int t = 0; t < 14; t++)
					{
						fireworks[i].trail[t][0] = fireworks[i].trail[t + 1][0];
						fireworks[i].trail[t][1] = fireworks[i].trail[t + 1][1];
					}
					fireworks[i].trail[14][0] = fireworks[i].x;
					fireworks[i].trail[14][1] = fireworks[i].y;
				}

				// Взрыв
				if (fireworks[i].explosionTime <= 0 || fireworks[i].y <= fireworks[i].targetY)
				{
					fireworks[i].exploded = true;

					int color1 = fireworks[i].colorIndex;
					int color2 = (fireworks[i].colorIndex + randomRange(1, 4)) % colorCount;
					int color3 = (fireworks[i].colorIndex + randomRange(2, 5)) % colorCount;

					// Основные частицы
					for (int p = 0; p < fireworks[i].particleCount; p++)
					{
						Particle part;
						part.x = fireworks[i].x;
						part.y = fireworks[i].y;

						float angle = randomFloat() * 6.28f;
						float speed = randomFloat() * 400.0f + 80.0f;
						part.vx = cosf(angle) * speed;
						part.vy = sinf(angle) * speed;

						part.life = randomFloat() * 3.0f + 1.5f;
						part.maxLife = part.life;

						int colorChoice = rand() % 3;
						if (colorChoice == 0) part.colorIndex = color1;
						else if (colorChoice == 1) part.colorIndex = color2;
						else part.colorIndex = color3;

						part.gravity = randomFloat() * 80.0f + 40.0f;
						part.size = randomFloat() * 3.0f + 1.0f;

						if ((int)particles.size() < maxParticles)
						{
							particles.push_back(part);
						}
					}

					// Крупные искры
					for (int s = 0; s < 50; s++)
					{
						Spark spark;
						spark.x = fireworks[i].x;
						spark.y = fireworks[i].y;
						spark.vx = (randomFloat() - 0.5f) * 500.0f;
						spark.vy = (randomFloat() - 0.5f) * 500.0f;
						spark.life = randomFloat() * 1.0f + 0.5f;
						spark.maxLife = spark.life;
						spark.colorIndex = rand() % 3 == 0 ? color1 : color2;

						if ((int)sparks.size() < maxSparks)
						{
							sparks.push_back(spark);
						}
					}
				}
			}
		}

		// Обновление частиц
		for (size_t i = 0; i < particles.size(); i++)
		{
			particles[i].x += particles[i].vx * deltaTime;
			particles[i].y += particles[i].vy * deltaTime;
			particles[i].vy += particles[i].gravity * deltaTime;
			particles[i].vx *= 0.995f;
			particles[i].life -= deltaTime;
		}

		// Обновление искр
		for (size_t i = 0; i < sparks.size(); i++)
		{
			sparks[i].x += sparks[i].vx * deltaTime;
			sparks[i].y += sparks[i].vy * deltaTime;
			sparks[i].vy += 120.0f * deltaTime;
			sparks[i].life -= deltaTime;
		}

		// Удаление мертвых частиц
		for (int i = (int)particles.size() - 1; i >= 0; i--)
		{
			if (particles[i].life <= 0)
			{
				particles.erase(particles.begin() + i);
			}
		}

		// Удаление мертвых искр
		for (int i = (int)sparks.size() - 1; i >= 0; i--)
		{
			if (sparks[i].life <= 0)
			{
				sparks.erase(sparks.begin() + i);
			}
		}

		// Удаление взорвавшихся фейерверков
		for (int i = (int)fireworks.size() - 1; i >= 0; i--)
		{
			if (fireworks[i].exploded)
			{
				fireworks.erase(fireworks.begin() + i);
			}
		}

		render.Begin();

		// Темное небо
		render.SetColor(LDL::Color(3, 3, 12));
		render.Clear();

		// Градиент неба
		for (int y = 0; y < windowHeight; y++)
		{
			float t = (float)y / windowHeight;
			render.SetColor(LDL::Color(
				(unsigned char)(3 + t * 8),
				(unsigned char)(3 + t * 4),
				(unsigned char)(12 + t * 18)
			));
			render.Fill(LDL::Vec2i(0, y), LDL::Vec2i(windowWidth, 1));
		}

		// Земля
		for (int y = windowHeight - 40; y < windowHeight; y++)
		{
			float t = (float)(y - (windowHeight - 40)) / 40.0f;
			render.SetColor(LDL::Color(
				(unsigned char)(15 + t * 10),
				(unsigned char)(20 + t * 5),
				(unsigned char)(10 + t * 5)
			));
			render.Fill(LDL::Vec2i(0, y), LDL::Vec2i(windowWidth, 1));
		}

		// Отрисовка хвостов частиц (сначала, чтобы были под частицами)
		for (size_t i = 0; i < particles.size(); i++)
		{
			if (particles[i].life > 0.3f)
			{
				float lifeRatio = particles[i].life / particles[i].maxLife;
				int tailLength = (int)(particles[i].size * 3);

				for (int t = 1; t <= tailLength; t++)
				{
					float tailAlpha = lifeRatio * (1.0f - (float)t / tailLength) * 0.6f;
					int tailX = (int)(particles[i].x - particles[i].vx * deltaTime * t * 1.5f);
					int tailY = (int)(particles[i].y - particles[i].vy * deltaTime * t * 1.5f);

					render.SetColor(LDL::Color(
						(unsigned char)(fireworkColors[particles[i].colorIndex].r * tailAlpha),
						(unsigned char)(fireworkColors[particles[i].colorIndex].g * tailAlpha),
						(unsigned char)(fireworkColors[particles[i].colorIndex].b * tailAlpha)
					));

					int tailSize = (int)(particles[i].size * (1.0f - (float)t / tailLength));
					if (tailSize < 1) tailSize = 1;
					render.Fill(LDL::Vec2i(tailX, tailY), LDL::Vec2i(tailSize, tailSize));
				}
			}
		}

		// Отрисовка частиц
		for (size_t i = 0; i < particles.size(); i++)
		{
			float lifeRatio = particles[i].life / particles[i].maxLife;
			float flicker = 0.7f + randomFloat() * 0.3f;

			int sizeIndex = (int)(particles[i].size * lifeRatio);
			if (sizeIndex < 0) sizeIndex = 0;
			if (sizeIndex >= particleSizes) sizeIndex = particleSizes - 1;

			LDL::Color particleColor(
				(unsigned char)(fireworkColors[particles[i].colorIndex].r * flicker),
				(unsigned char)(fireworkColors[particles[i].colorIndex].g * flicker),
				(unsigned char)(fireworkColors[particles[i].colorIndex].b * flicker)
			);

			// Используем текстуру
			render.Draw(particleTextures[particles[i].colorIndex][sizeIndex],
				LDL::Vec2i((int)particles[i].x, (int)particles[i].y));

			// Дополнительное свечение для крупных частиц
			if (particles[i].size > 2.0f && lifeRatio > 0.5f)
			{
				render.SetColor(LDL::Color(
					(unsigned char)(particleColor.r * 0.3f),
					(unsigned char)(particleColor.g * 0.3f),
					(unsigned char)(particleColor.b * 0.3f)
				));
				render.Fill(LDL::Vec2i((int)particles[i].x - 2, (int)particles[i].y - 2),
					LDL::Vec2i(5, 5));
			}
		}

		// Отрисовка искр
		for (size_t i = 0; i < sparks.size(); i++)
		{
			float lifeRatio = sparks[i].life / sparks[i].maxLife;
			int sizeIndex = (int)(lifeRatio * 2);
			if (sizeIndex < 0) sizeIndex = 0;
			if (sizeIndex >= 3) sizeIndex = 2;

			render.Draw(sparkTextures[sparks[i].colorIndex][sizeIndex],
				LDL::Vec2i((int)sparks[i].x, (int)sparks[i].y));
		}

		// Отрисовка летящих ракет
		for (size_t i = 0; i < fireworks.size(); i++)
		{
			if (!fireworks[i].exploded)
			{
				// Трек
				for (int t = 0; t < fireworks[i].trailLength; t++)
				{
					float alpha = (float)t / 15.0f * 0.8f;
					int trailSize = 1 + t / 5;

					render.SetColor(LDL::Color(
						(unsigned char)(fireworkColors[fireworks[i].colorIndex].r * alpha),
						(unsigned char)(fireworkColors[fireworks[i].colorIndex].g * alpha),
						(unsigned char)(fireworkColors[fireworks[i].colorIndex].b * alpha)
					));
					render.Fill(LDL::Vec2i((int)fireworks[i].trail[t][0],
						(int)fireworks[i].trail[t][1]), LDL::Vec2i(trailSize, trailSize));
				}

				// Голова ракеты (крупная)
				render.SetColor(fireworkColors[fireworks[i].colorIndex]);
				render.Fill(LDL::Vec2i((int)fireworks[i].x - 2, (int)fireworks[i].y - 2),
					LDL::Vec2i(5, 5));
				render.SetColor(LDL::Color(255, 255, 255));
				render.Fill(LDL::Vec2i((int)fireworks[i].x, (int)fireworks[i].y),
					LDL::Vec2i(2, 2));
			}
		}

		// Отражения на земле
		for (size_t i = 0; i < particles.size(); i++)
		{
			if (particles[i].y > windowHeight - 80 && particles[i].life > 0.5f)
			{
				float lifeRatio = particles[i].life / particles[i].maxLife;
				int reflectY = windowHeight - 40 + (windowHeight - 40 - (int)particles[i].y);

				if (reflectY < windowHeight && reflectY >= windowHeight - 40)
				{
					render.SetColor(LDL::Color(
						(unsigned char)(fireworkColors[particles[i].colorIndex].r * lifeRatio * 0.25f),
						(unsigned char)(fireworkColors[particles[i].colorIndex].g * lifeRatio * 0.25f),
						(unsigned char)(fireworkColors[particles[i].colorIndex].b * lifeRatio * 0.25f)
					));
					int refSize = (int)(particles[i].size * 0.7f);
					render.Fill(LDL::Vec2i((int)particles[i].x, reflectY),
						LDL::Vec2i(refSize, 2));
				}
			}
		}

		// Подсказка
		render.Draw(infoText, LDL::Vec2i(10, 10));

		// Статистика
		char statsText[150];
		sprintf(statsText, "Particles: %d | Fireworks: %d | Sparks: %d | MAX: %d",
			(int)particles.size(), (int)fireworks.size(), (int)sparks.size(), maxParticles);
		rasterizer.Text(&infoFont, LDL::Color(180, 180, 180), statsText);
		LDL::Texture* statsTexture = new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels());
		render.Draw(statsTexture, LDL::Vec2i(10, 25));
		delete statsTexture;

		render.End();
	}

	// Очистка памяти
	delete infoText;

	for (size_t c = 0; c < particleTextures.size(); c++)
	{
		for (size_t s = 0; s < particleTextures[c].size(); s++)
		{
			delete particleTextures[c][s];
		}
	}

	for (size_t c = 0; c < sparkTextures.size(); c++)
	{
		for (size_t s = 0; s < sparkTextures[c].size(); s++)
		{
			delete sparkTextures[c][s];
		}
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}
