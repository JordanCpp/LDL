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

struct DropColumn
{
	float y;
	float speed;
	int charIndex;
	int colorIndex;
	int x;
};

int randomRange(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

int main()
{
	srand((unsigned int)time(NULL));

	LDL::Result result;
	LDL::Context context(result);
	LDL::Event event;
	LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600),
		"LDL C++98 - Rainbow Matrix Waterfall", LDL::Window::Resized);
	LDL::Render2D render(result, context, window);
	LDL::Rasterizer rasterizer(result);
	SimpleTimer timer;

	// Шрифт для символов
	LDL::Font waterfallFont(result, "Files/Lato-Bold.ttf", 16);

	// Символы для водопада (только буквы и цифры)
	const char* waterfallChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int charsLength = strlen(waterfallChars);

	// Цвета для колонок
	const int colorCount = 6;
	LDL::Color colors[colorCount] = {
		LDL::Color(255, 100, 100),  // Красный
		LDL::Color(100, 255, 100),  // Зеленый
		LDL::Color(100, 100, 255),  // Синий
		LDL::Color(255, 255, 100),  // Желтый
		LDL::Color(255, 100, 255),  // Пурпурный
		LDL::Color(100, 255, 255)   // Голубой
	};

	// Заранее создаем текстуры для каждого символа и каждого цвета с разной яркостью
	const int brightnessLevels = 10;
	std::vector<std::vector<std::vector<LDL::Texture*> > > charTextures;

	for (int c = 0; c < colorCount; c++)
	{
		std::vector<std::vector<LDL::Texture*> > colorTextures;
		for (int i = 0; i < charsLength; i++)
		{
			std::vector<LDL::Texture*> brightnessTextures;
			char singleChar[2] = { waterfallChars[i], '\0' };

			for (int b = 0; b < brightnessLevels; b++)
			{
				float brightness = 1.0f - (float)b / brightnessLevels;
				LDL::Color charColor(
					(unsigned char)(colors[c].r * brightness),
					(unsigned char)(colors[c].g * brightness),
					(unsigned char)(colors[c].b * brightness)
				);

				rasterizer.Text(&waterfallFont, charColor, singleChar);
				brightnessTextures.push_back(new LDL::Texture(result, context,
					rasterizer.GetPixelFormat(), rasterizer.GetSize(),
					rasterizer.GetPixels()));
			}
			colorTextures.push_back(brightnessTextures);
		}
		charTextures.push_back(colorTextures);
	}

	// Текстура для белой головы (яркая)
	std::vector<LDL::Texture*> whiteTextures;
	for (int i = 0; i < charsLength; i++)
	{
		char singleChar[2] = { waterfallChars[i], '\0' };
		rasterizer.Text(&waterfallFont, LDL::Color(255, 255, 255), singleChar);
		whiteTextures.push_back(new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels()));
	}

	int windowWidth = 800;
	int windowHeight = 600;
	int columnWidth = 18;
	int maxColumns = windowWidth / columnWidth;

	// Создаем колонки
	std::vector<DropColumn> columns;
	for (int i = 0; i < maxColumns; i++)
	{
		DropColumn col;
		col.y = (float)randomRange(-windowHeight, 0);
		col.speed = 60.0f + (float)randomRange(0, 100);
		col.charIndex = rand() % charsLength;
		col.colorIndex = rand() % colorCount;
		col.x = i * columnWidth;
		columns.push_back(col);
	}

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
				windowWidth = window.GetSize().x;
				windowHeight = window.GetSize().y;

				int newMaxColumns = windowWidth / columnWidth;
				if (newMaxColumns != maxColumns)
				{
					columns.clear();
					for (int i = 0; i < newMaxColumns; i++)
					{
						DropColumn col;
						col.y = (float)randomRange(-windowHeight, 0);
						col.speed = 60.0f + (float)randomRange(0, 100);
						col.charIndex = rand() % charsLength;
						col.colorIndex = rand() % colorCount;
						col.x = i * columnWidth;
						columns.push_back(col);
					}
					maxColumns = newMaxColumns;
				}
			}
		}

		// Обновление позиций колонок
		for (size_t i = 0; i < columns.size(); i++)
		{
			columns[i].y += columns[i].speed * deltaTime;

			if (columns[i].y > windowHeight + 50)
			{
				columns[i].y = (float)randomRange(-200, -20);
				columns[i].speed = 60.0f + (float)randomRange(0, 100);
				columns[i].charIndex = rand() % charsLength;
				columns[i].colorIndex = rand() % colorCount;
			}
		}

		render.Begin();

		// Черный фон
		render.SetColor(LDL::Color(0, 0, 0));
		render.Clear();

		// Отрисовка падающих символов
		for (size_t i = 0; i < columns.size(); i++)
		{
			// Рисуем хвост из символов
			for (int j = 0; j < brightnessLevels; j++)
			{
				int charIdx = (columns[i].charIndex + j) % charsLength;
				int yPos = (int)columns[i].y - j * 16;

				// Пропускаем символы за пределами экрана
				if (yPos < -20 || yPos > windowHeight + 20)
				{
					continue;
				}

				if (j == 0)
				{
					// Голова - яркая белая
					render.Draw(whiteTextures[charIdx], LDL::Vec2i(columns[i].x, yPos));
				}
				else
				{
					// Хвост - цветной затухающий
					render.Draw(charTextures[columns[i].colorIndex][charIdx][j],
						LDL::Vec2i(columns[i].x, yPos));
				}
			}
		}

		render.End();
	}

	// Очистка памяти
	for (int c = 0; c < colorCount; c++)
	{
		for (int i = 0; i < charsLength; i++)
		{
			for (int b = 0; b < brightnessLevels; b++)
			{
				delete charTextures[c][i][b];
			}
		}
	}

	for (int i = 0; i < charsLength; i++)
	{
		delete whiteTextures[i];
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}