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

struct MagicParticle
{
	float x, y;
	float vx, vy;
	float life;
	float maxLife;
	float size;
	float phase;
	float speed;
	float orbitRadius;
	float orbitAngle;
	int colorIndex;
	bool trailing;
};

struct TrailPoint
{
	float x, y;
	float life;
	float maxLife;
	int colorIndex;
	float size;
};

struct SpiralEmitter
{
	float x, y;
	float angle;
	float radius;
	float rotationSpeed;
	float pulsePhase;
	int colorIndex;
	bool active;
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
		"LDL C++98 - Magic Pollen", LDL::Window::Resized);
	LDL::Render2D render(result, context, window);
	LDL::Rasterizer rasterizer(result);

	// Шрифты
	LDL::Font particleFont(result, "Files/Lato-Bold.ttf", 10);
	LDL::Font infoFont(result, "Files/Lato-Bold.ttf", 14);
	LDL::Font titleFont(result, "Files/Lato-Bold.ttf", 24);

	// Текстура для подсказки
	rasterizer.Text(&infoFont, LDL::Color(200, 200, 200),
		"Magic Pollen - Move mouse to attract | Press ESC to exit | SPACE to change mode");
	LDL::Texture* infoText = new LDL::Texture(result, context,
		rasterizer.GetPixelFormat(), rasterizer.GetSize(),
		rasterizer.GetPixels());

	// Волшебные цвета
	const int colorCount = 12;
	LDL::Color magicColors[colorCount] = {
		LDL::Color(255, 200, 50),   // Золотой
		LDL::Color(255, 150, 200),  // Розовый
		LDL::Color(150, 200, 255),  // Голубой
		LDL::Color(200, 255, 150),  // Лаймовый
		LDL::Color(255, 100, 150),  // Коралловый
		LDL::Color(150, 100, 255),  // Фиолетовый
		LDL::Color(255, 255, 150),  // Лимонный
		LDL::Color(100, 255, 200),  // Мятный
		LDL::Color(255, 180, 100),  // Персиковый
		LDL::Color(180, 150, 255),  // Лавандовый
		LDL::Color(255, 200, 200),  // Светло-розовый
		LDL::Color(200, 220, 255)   // Небесный
	};

	// Создаем текстуры частиц разных размеров
	const int particleSizes = 5;
	std::vector<std::vector<LDL::Texture*> > particleTextures;

	for (int c = 0; c < colorCount; c++)
	{
		std::vector<LDL::Texture*> sizeTextures;
		for (int s = 1; s <= particleSizes; s++)
		{
			int fontSize = 4 + s * 3; // 7, 10, 13, 16, 19
			LDL::Font sizedFont(result, "Files/Lato-Bold.ttf", fontSize);
			rasterizer.Text(&sizedFont, magicColors[c], "*");
			sizeTextures.push_back(new LDL::Texture(result, context,
				rasterizer.GetPixelFormat(), rasterizer.GetSize(),
				rasterizer.GetPixels()));
		}
		particleTextures.push_back(sizeTextures);
	}

	// Текстуры для трейлов (маленькие точки)
	std::vector<std::vector<LDL::Texture*> > trailTextures;
	for (int c = 0; c < colorCount; c++)
	{
		std::vector<LDL::Texture*> sizeTextures;
		for (int s = 1; s <= 3; s++)
		{
			LDL::Font sizedFont(result, "Files/Lato-Bold.ttf", 4 + s);
			rasterizer.Text(&sizedFont, magicColors[c], ".");
			sizeTextures.push_back(new LDL::Texture(result, context,
				rasterizer.GetPixelFormat(), rasterizer.GetSize(),
				rasterizer.GetPixels()));
		}
		trailTextures.push_back(sizeTextures);
	}

	// Текстуры для названий режимов
	const char* modeNames[3] = { "Free Flow", "Spiral Dance", "Gravity Well" };
	std::vector<LDL::Texture*> modeTextures;
	for (int i = 0; i < 3; i++)
	{
		rasterizer.Text(&titleFont, magicColors[i * 4], modeNames[i]);
		modeTextures.push_back(new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels()));
	}

	int windowWidth = 800;
	int windowHeight = 600;

	// Частицы
	const int maxParticles = 300;
	std::vector<MagicParticle> particles;

	for (int i = 0; i < maxParticles; i++)
	{
		MagicParticle mp;
		mp.x = randomFloat() * windowWidth;
		mp.y = randomFloat() * windowHeight;
		mp.vx = (randomFloat() - 0.5f) * 40.0f;
		mp.vy = (randomFloat() - 0.5f) * 40.0f;
		mp.life = randomFloat() * 5.0f + 2.0f;
		mp.maxLife = mp.life;
		mp.size = randomFloat() * 4.0f + 0.5f;
		mp.phase = randomFloat() * 6.28f;
		mp.speed = randomFloat() * 30.0f + 10.0f;
		mp.orbitRadius = randomFloat() * 50.0f + 20.0f;
		mp.orbitAngle = randomFloat() * 6.28f;
		mp.colorIndex = rand() % colorCount;
		mp.trailing = (rand() % 3 == 0);
		particles.push_back(mp);
	}

	// Трейлы
	std::vector<TrailPoint> trails;
	const int maxTrails = 1000;

	// Спиральные эмиттеры
	const int maxEmitters = 5;
	std::vector<SpiralEmitter> emitters;

	// Режимы
	int currentMode = 0; // 0: свободный, 1: спиральный, 2: гравитационный
	float modeDisplayTimer = 0;

	// Мышь
	int mouseX = windowWidth / 2;
	int mouseY = windowHeight / 2;
	bool mouseOnScreen = false;

	// LDL::Ticks
	unsigned int startTicks = LDL::Ticks();
	unsigned int lastTicks = startTicks;
	unsigned int lastEmitterTicks = startTicks;

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
				mouseY = event.u.Mouse.PosY;
				mouseOnScreen = true;
			}
			else if (event.IsKeyPressed(LDL_KeySpace))
			{
				currentMode = (currentMode + 1) % 3;
				modeDisplayTimer = 2.0f;

				// Очищаем эмиттеры при смене режима
				if (currentMode != 1)
				{
					emitters.clear();
				}
			}
		}

		if (modeDisplayTimer > 0)
		{
			modeDisplayTimer -= deltaTime;
		}

		// Создание спиральных эмиттеров в режиме 1
		if (currentMode == 1 && currentTicks - lastEmitterTicks > 5000)
		{
			if ((int)emitters.size() < maxEmitters)
			{
				SpiralEmitter emitter;
				emitter.x = randomFloat() * windowWidth * 0.6f + windowWidth * 0.2f;
				emitter.y = randomFloat() * windowHeight * 0.6f + windowHeight * 0.2f;
				emitter.angle = randomFloat() * 6.28f;
				emitter.radius = 0;
				emitter.rotationSpeed = randomFloat() * 2.0f + 1.0f;
				emitter.pulsePhase = randomFloat() * 6.28f;
				emitter.colorIndex = rand() % colorCount;
				emitter.active = true;
				emitters.push_back(emitter);
			}
			lastEmitterTicks = currentTicks;
		}

		// Обновление эмиттеров
		for (size_t i = 0; i < emitters.size(); i++)
		{
			emitters[i].angle += emitters[i].rotationSpeed * deltaTime;
			emitters[i].radius = 50.0f + sinf(currentTime * 2.0f + emitters[i].pulsePhase) * 30.0f;

			// Создание частиц из эмиттера
			if (rand() % 100 < 30 && (int)particles.size() < maxParticles + 50)
			{
				MagicParticle mp;
				mp.x = emitters[i].x + cosf(emitters[i].angle) * emitters[i].radius;
				mp.y = emitters[i].y + sinf(emitters[i].angle) * emitters[i].radius;
				mp.vx = cosf(emitters[i].angle) * 50.0f;
				mp.vy = sinf(emitters[i].angle) * 50.0f;
				mp.life = randomFloat() * 3.0f + 1.0f;
				mp.maxLife = mp.life;
				mp.size = randomFloat() * 3.0f + 0.5f;
				mp.phase = randomFloat() * 6.28f;
				mp.speed = randomFloat() * 20.0f + 5.0f;
				mp.orbitRadius = randomFloat() * 30.0f + 10.0f;
				mp.orbitAngle = randomFloat() * 6.28f;
				mp.colorIndex = emitters[i].colorIndex;
				mp.trailing = true;
				particles.push_back(mp);
			}
		}

		// Обновление частиц
		for (size_t i = 0; i < particles.size(); i++)
		{
			float lifeRatio = particles[i].life / particles[i].maxLife;

			switch (currentMode)
			{
			case 0: // Свободный поток
			{
				// Плавное движение с синусоидами
				particles[i].vx += sinf(currentTime * 2.0f + particles[i].phase) * 20.0f * deltaTime;
				particles[i].vy += cosf(currentTime * 1.7f + particles[i].phase) * 20.0f * deltaTime;

				// Притяжение к мыши
				if (mouseOnScreen)
				{
					float dx = mouseX - particles[i].x;
					float dy = mouseY - particles[i].y;
					float dist = sqrtf(dx * dx + dy * dy);

					if (dist < 200.0f && dist > 10.0f)
					{
						float force = 150.0f / dist;
						particles[i].vx += (dx / dist) * force * deltaTime;
						particles[i].vy += (dy / dist) * force * deltaTime;
					}
				}
				break;
			}
			case 1: // Спиральный танец
			{
				// Орбитальное движение вокруг ближайшего эмиттера
				if (!emitters.empty())
				{
					int nearestEmitter = 0;
					float minDist = 10000.0f;

					for (size_t e = 0; e < emitters.size(); e++)
					{
						float dx = emitters[e].x - particles[i].x;
						float dy = emitters[e].y - particles[i].y;
						float dist = sqrtf(dx * dx + dy * dy);

						if (dist < minDist)
						{
							minDist = dist;
							nearestEmitter = (int)e;
						}
					}

					particles[i].orbitAngle += particles[i].speed * deltaTime;
					float targetX = emitters[nearestEmitter].x + cosf(particles[i].orbitAngle) * particles[i].orbitRadius;
					float targetY = emitters[nearestEmitter].y + sinf(particles[i].orbitAngle) * particles[i].orbitRadius;

					particles[i].vx = (targetX - particles[i].x) * 5.0f;
					particles[i].vy = (targetY - particles[i].y) * 5.0f;
				}
				break;
			}
			case 2: // Гравитационный колодец
			{
				// Притяжение к центру экрана
				float cx = windowWidth / 2.0f;
				float cy = windowHeight / 2.0f;

				float dx = cx - particles[i].x;
				float dy = cy - particles[i].y;
				float dist = sqrtf(dx * dx + dy * dy);

				if (dist > 5.0f)
				{
					float force = 80.0f / (dist * 0.3f);
					particles[i].vx += (dx / dist) * force * deltaTime;
					particles[i].vy += (dy / dist) * force * deltaTime;
				}

				// Отталкивание от мыши
				if (mouseOnScreen)
				{
					float mx = mouseX - particles[i].x;
					float my = mouseY - particles[i].y;
					float mdist = sqrtf(mx * mx + my * my);

					if (mdist < 150.0f && mdist > 5.0f)
					{
						float force = -200.0f / mdist;
						particles[i].vx += (mx / mdist) * force * deltaTime;
						particles[i].vy += (my / mdist) * force * deltaTime;
					}
				}
				break;
			}
			}

			// Торможение
			particles[i].vx *= 0.98f;
			particles[i].vy *= 0.98f;

			// Движение
			particles[i].x += particles[i].vx * deltaTime;
			particles[i].y += particles[i].vy * deltaTime;

			// Границы экрана (отражение)
			if (particles[i].x < 0) { particles[i].x = 0; particles[i].vx *= -0.5f; }
			if (particles[i].x > windowWidth) { particles[i].x = (float)windowWidth; particles[i].vx *= -0.5f; }
			if (particles[i].y < 0) { particles[i].y = 0; particles[i].vy *= -0.5f; }
			if (particles[i].y > windowHeight) { particles[i].y = (float)windowHeight; particles[i].vy *= -0.5f; }

			// Время жизни
			particles[i].life -= deltaTime;

			// Создание трейлов
			if (particles[i].trailing && lifeRatio > 0.3f && rand() % 100 < 40)
			{
				TrailPoint trail;
				trail.x = particles[i].x;
				trail.y = particles[i].y;
				trail.life = randomFloat() * 0.5f + 0.2f;
				trail.maxLife = trail.life;
				trail.colorIndex = particles[i].colorIndex;
				trail.size = particles[i].size * 0.5f;

				if ((int)trails.size() < maxTrails)
				{
					trails.push_back(trail);
				}
			}
		}

		// Удаление мертвых частиц
		for (int i = (int)particles.size() - 1; i >= 0; i--)
		{
			if (particles[i].life <= 0)
			{
				// Возрождаем частицу
				particles[i].x = randomFloat() * windowWidth;
				particles[i].y = randomFloat() * windowHeight;
				particles[i].vx = (randomFloat() - 0.5f) * 40.0f;
				particles[i].vy = (randomFloat() - 0.5f) * 40.0f;
				particles[i].life = randomFloat() * 5.0f + 2.0f;
				particles[i].maxLife = particles[i].life;
				particles[i].size = randomFloat() * 4.0f + 0.5f;
				particles[i].phase = randomFloat() * 6.28f;
				particles[i].colorIndex = rand() % colorCount;
				particles[i].trailing = (rand() % 3 == 0);
			}
		}

		// Обновление трейлов
		for (size_t i = 0; i < trails.size(); i++)
		{
			trails[i].life -= deltaTime;
		}

		// Удаление мертвых трейлов
		for (int i = (int)trails.size() - 1; i >= 0; i--)
		{
			if (trails[i].life <= 0)
			{
				trails.erase(trails.begin() + i);
			}
		}

		render.Begin();

		// Темный волшебный фон
		render.SetColor(LDL::Color(8, 5, 20));
		render.Clear();

		// Градиент фона
		for (int y = 0; y < windowHeight; y++)
		{
			float t = (float)y / windowHeight;
			render.SetColor(LDL::Color(
				(unsigned char)(8 + t * 10),
				(unsigned char)(5 + t * 8),
				(unsigned char)(20 + t * 15)
			));
			render.Fill(LDL::Vec2i(0, y), LDL::Vec2i(windowWidth, 1));
		}

		// Отрисовка эмиттеров (в спиральном режиме)
		if (currentMode == 1)
		{
			for (size_t i = 0; i < emitters.size(); i++)
			{
				// Пульсирующее свечение
				float pulse = sinf(currentTime * 3.0f + emitters[i].pulsePhase) * 0.5f + 0.5f;
				int glowRadius = (int)(15 + pulse * 10);

				for (int dy = -glowRadius; dy <= glowRadius; dy++)
				{
					for (int dx = -glowRadius; dx <= glowRadius; dx++)
					{
						float dist = sqrtf((float)(dx * dx + dy * dy));
						if (dist < glowRadius)
						{
							float alpha = (1.0f - dist / glowRadius) * 0.5f * pulse;
							int px = (int)emitters[i].x + dx;
							int py = (int)emitters[i].y + dy;

							if (px >= 0 && px < windowWidth && py >= 0 && py < windowHeight)
							{
								render.SetColor(LDL::Color(
									(unsigned char)(magicColors[emitters[i].colorIndex].r * alpha),
									(unsigned char)(magicColors[emitters[i].colorIndex].g * alpha),
									(unsigned char)(magicColors[emitters[i].colorIndex].b * alpha)
								));
								render.Fill(LDL::Vec2i(px, py), LDL::Vec2i(1, 1));
							}
						}
					}
				}
			}
		}

		// Отрисовка трейлов (под частицами)
		for (size_t i = 0; i < trails.size(); i++)
		{
			float lifeRatio = trails[i].life / trails[i].maxLife;
			int sizeIndex = (int)(trails[i].size * lifeRatio);
			if (sizeIndex < 0) sizeIndex = 0;
			if (sizeIndex >= 3) sizeIndex = 2;

			render.Draw(trailTextures[trails[i].colorIndex][sizeIndex],
				LDL::Vec2i((int)trails[i].x, (int)trails[i].y));
		}

		// Отрисовка частиц
		for (size_t i = 0; i < particles.size(); i++)
		{
			float lifeRatio = particles[i].life / particles[i].maxLife;
			float flicker = 0.7f + randomFloat() * 0.3f;

			int sizeIndex = (int)(particles[i].size * lifeRatio);
			if (sizeIndex < 0) sizeIndex = 0;
			if (sizeIndex >= particleSizes) sizeIndex = particleSizes - 1;

			render.Draw(particleTextures[particles[i].colorIndex][sizeIndex],
				LDL::Vec2i((int)particles[i].x, (int)particles[i].y));

			// Свечение для крупных частиц
			if (particles[i].size > 2.5f && lifeRatio > 0.5f)
			{
				float glowAlpha = lifeRatio * 0.3f;
				render.SetColor(LDL::Color(
					(unsigned char)(magicColors[particles[i].colorIndex].r * glowAlpha),
					(unsigned char)(magicColors[particles[i].colorIndex].g * glowAlpha),
					(unsigned char)(magicColors[particles[i].colorIndex].b * glowAlpha)
				));
				render.Fill(LDL::Vec2i((int)particles[i].x - 4, (int)particles[i].y - 4),
					LDL::Vec2i(9, 9));
			}
		}

		// Гравитационный колодец (визуализация в режиме 2)
		if (currentMode == 2)
		{
			int cx = windowWidth / 2;
			int cy = windowHeight / 2;

			for (int ring = 0; ring < 3; ring++)
			{
				float ringRadius = 80.0f + ring * 60.0f;
				float ringAlpha = 0.15f - ring * 0.04f;

				for (int angle = 0; angle < 360; angle += 2)
				{
					float rad = angle * 3.14159f / 180.0f;
					int px = cx + (int)(cosf(rad) * ringRadius);
					int py = cy + (int)(sinf(rad) * ringRadius);

					if (px >= 0 && px < windowWidth && py >= 0 && py < windowHeight)
					{
						render.SetColor(LDL::Color(
							(unsigned char)(100 * ringAlpha),
							(unsigned char)(100 * ringAlpha),
							(unsigned char)(200 * ringAlpha)
						));
						render.Fill(LDL::Vec2i(px, py), LDL::Vec2i(2, 2));
					}
				}
			}
		}

		// Курсор мыши (свечение)
		if (mouseOnScreen)
		{
			int cursorGlow = 15;
			for (int dy = -cursorGlow; dy <= cursorGlow; dy++)
			{
				for (int dx = -cursorGlow; dx <= cursorGlow; dx++)
				{
					float dist = sqrtf((float)(dx * dx + dy * dy));
					if (dist < cursorGlow)
					{
						float alpha = (1.0f - dist / cursorGlow) * 0.3f;
						int px = mouseX + dx;
						int py = mouseY + dy;

						if (px >= 0 && px < windowWidth && py >= 0 && py < windowHeight)
						{
							render.SetColor(LDL::Color(
								(unsigned char)(255 * alpha),
								(unsigned char)(255 * alpha),
								(unsigned char)(255 * alpha)
							));
							render.Fill(LDL::Vec2i(px, py), LDL::Vec2i(1, 1));
						}
					}
				}
			}
		}

		// Название режима
		if (modeDisplayTimer > 0)
		{
			float alpha = modeDisplayTimer > 1.5f ? 1.0f : modeDisplayTimer / 1.5f;
			render.Draw(modeTextures[currentMode],
				LDL::Vec2i(windowWidth / 2 - 80, windowHeight / 2 - 30));
		}

		// Подсказка
		render.Draw(infoText, LDL::Vec2i(10, 10));

		// Статистика
		char statsText[150];
		sprintf(statsText, "Mode: %s | Particles: %d | Trails: %d | Emitters: %d",
			modeNames[currentMode], (int)particles.size(), (int)trails.size(), (int)emitters.size());
		rasterizer.Text(&infoFont, LDL::Color(150, 140, 180), statsText);
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

	for (size_t c = 0; c < trailTextures.size(); c++)
	{
		for (size_t s = 0; s < trailTextures[c].size(); s++)
		{
			delete trailTextures[c][s];
		}
	}

	for (size_t i = 0; i < modeTextures.size(); i++)
	{
		delete modeTextures[i];
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}
