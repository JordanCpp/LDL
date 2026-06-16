/*
 * -----------------------------------------------------------------------------
 * Hyperdrive Effect - FINAL SAFETY VERSION
 * Исправлено: жесткое ограничение координат (Clamping) для исключения огромных квадратов.
 * -----------------------------------------------------------------------------
 */

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <LDL/C++98/LDL.hpp>

struct Star
{
	float x, y, z;
	float speed;
	LDL::Color color;
};

float randomFloat() { return (float)rand() / (float)RAND_MAX; }

int main()
{
	srand((unsigned int)time(NULL));

	LDL::Result result;
	LDL::Context context(result);
	LDL::Event event;

	int windowWidth = 800;
	int windowHeight = 600;
	LDL::Window window(result, context, LDL::Vec2i(100, 100), LDL::Vec2i(windowWidth, windowHeight),
		"LDL API - Hyperdrive (Fixed)", LDL::Window::Resized);

	LDL::Render2D render(result, context, window);
	LDL::Rasterizer rasterizer(result);

	// Настройки звездного поля
	const int maxStars = 500;
	std::vector<Star> stars;
	float warpFactor = 1.0f;

	LDL::Color palette[] = {
		LDL::Color(100, 150, 255),
		LDL::Color(150, 200, 255),
		LDL::Color(255, 255, 255)
	};

	// Функция инициализации (теперь Z всегда в разумных пределах)
	auto initStar = [&](Star& s) {
		s.x = (randomFloat() * 2.0f) - 1.0f;
		s.y = (randomFloat() * 2.0f) - 1.0f;
		s.z = 1.0f; // Начинаем с далекой дистанции
		s.speed = 0.15f + randomFloat() * 0.25f;
		s.color = palette[rand() % 3];
		};

	for (int i = 0; i < maxStars; ++i)
	{
		Star s;
		initStar(s);
		stars.push_back(s);
	}

	unsigned int lastTicks = LDL::Ticks();
	LDL::Font font(result, "Files/Lato-Bold.ttf", 16);

	while (window.IsRunning() && result.IsOk())
	{
		unsigned int currentTicks = LDL::Ticks();
		float deltaTime = (currentTicks - lastTicks) / 1000.0f;
		lastTicks = currentTicks;

		while (window.GetEvent(event))
		{
			if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape))
				window.StopEvent();

			if (event.IsKeyPressed(LDL_KeyUp)) warpFactor += 0.3f;
			if (event.IsKeyPressed(LDL_KeyDown)) warpFactor = std::max(1.0f, warpFactor - 0.3f);
		}

		// Обновление звезд
		for (size_t i = 0; i < stars.size(); ++i)
		{
			stars[i].z -= stars[i].speed * deltaTime * warpFactor;

			// Если звезда слишком близко, сбрасываем её в даль
			if (stars[i].z <= 0.05f)
			{
				initStar(stars[i]);
				stars[int(i)].z = 1.0f; // Ошибка была тут в логике, исправил на stars[i]
				stars[i].z = 1.0f;
			}
		}

		render.Begin();
		render.SetColor(LDL::Color(0, 0, 5)); // Фон
		render.Clear();

		float centerX = windowWidth / 2.0f;
		float centerY = windowHeight / 2.0f;
		float FOV = 300.0f; // Уменьшил FOV для стабильности чисел

		for (size_t i = 0; i < stars.size(); ++i)
		{
			// 1. Проекция
			float scale = FOV / stars[i].z;
			float screenX = centerX + (stars[i].x * scale);
			float screenY = centerY + (stars[i].y * scale);

			// 2. ЖЕСТКАЯ ПРОВЕРКА: Если точка за пределами экрана - игнорируем совсем
			if (screenX < -50 || screenX > windowWidth + 5 // Допустимый отступ для хвостов
				|| screenY < -50 || screenY > windowHeight + 5)
				continue;

			// 3. Расчет шлейфа
			float streakLength = (1.0f - stars[i].z) * 30.0f * warpFactor;

			// Точка начала и конца линии
			float yTop = screenY;
			float yBottom = screenY - streakLength;

			// 4. ЖЕСТКОЕ ОГРАНИЧЕНИЕ (Clamping) координат внутри экрана
			// Это предотвращает создание гигантских прямоугольников (квадратов)
			if (yBottom < 0) yBottom = 0;
			if (yTop > windowHeight) yTop = (float)windowHeight;

			// 5. Подготовка цвета
			float brightness = (1.0f - stars[i].z) * 100.0f;
			LDL::Color drawColor = stars[i].color;
			drawColor.r = (unsigned char)std::min(255.0f, drawColor.r + brightness);
			drawColor.g = (unsigned char)std::min(255.0f, drawColor.g + brightness);
			drawColor.b = (unsigned char)std::min(255.0f, drawColor.b + brightness);

			render.SetColor(drawColor);

			// 6. Отрисовка тонкой линии (толщина всегда 1-2 пикселя)
			int thickness = (stars[i].z < 0.3f) ? 2 : 1;

			// Используем min/max, чтобы Fill всегда получал корректный прямоугольник
			render.Fill(
				LDL::Vec2i((int)screenX, (int)yBottom),
				LDL::Vec2i((int)screenX + thickness, (int)yTop)
			);
		}

		// Интерфейс
		char speedStr[64];
		sprintf(speedStr, "WARP: x%.1f | [UP/DOWN]", warpFactor);
		rasterizer.Text(&font, LDL::Color(200, 200, 200), speedStr);
		LDL::Texture* uiTex = new LDL::Texture(result, context, rasterizer.GetPixelFormat(),
			rasterizer.GetSize(), rasterizer.GetPixels());
		render.Draw(uiTex, LDL::Vec2i(20, 20));
		delete uiTex;

		render.End();
	}

	return result.IsOk() ? 0 : -1;
}
