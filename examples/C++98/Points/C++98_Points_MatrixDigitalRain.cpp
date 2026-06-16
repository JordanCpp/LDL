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

struct DropColumn
{
	float y;
	float speed;
	int charIndex;
	int colorIndex;
	int x;
	float glowTimer;
};

struct FlashParticle
{
	float x, y;
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
		"LDL C++98 - Digital Rain Matrix", LDL::Window::Resized);
	LDL::Render2D render(result, context, window);
	LDL::Rasterizer rasterizer(result);

	// Шрифты
	LDL::Font rainFont(result, "Files/Lato-Bold.ttf", 18);
	LDL::Font infoFont(result, "Files/Lato-Bold.ttf", 14);
	LDL::Font titleFont(result, "Files/Lato-Bold.ttf", 28);

	// Текстура для подсказки
	rasterizer.Text(&infoFont, LDL::Color(150, 150, 150),
		"Matrix Digital Rain - Press ESC to exit | SPACE to change mode");
	LDL::Texture* infoText = new LDL::Texture(result, context,
		rasterizer.GetPixelFormat(), rasterizer.GetSize(),
		rasterizer.GetPixels());

	// Символы для дождя
	const char* rainChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int charsLength = strlen(rainChars);

	// Цветовые схемы
	const int colorSchemeCount = 5;
	const char* schemeNames[colorSchemeCount] = {
		"Classic Green",
		"Rainbow",
		"Ice Blue",
		"Fire",
		"Neon Purple"
	};

	LDL::Color schemeColors[colorSchemeCount][10] = {
		// Классический зеленый
		{
			LDL::Color(200, 255, 200),
			LDL::Color(150, 255, 150),
			LDL::Color(100, 255, 100),
			LDL::Color(50, 255, 50),
			LDL::Color(0, 255, 0),
			LDL::Color(0, 200, 0),
			LDL::Color(0, 150, 0),
			LDL::Color(0, 100, 0),
			LDL::Color(0, 60, 0),
			LDL::Color(0, 30, 0)
		},
		// Радужный
		{
			LDL::Color(255, 100, 100),
			LDL::Color(255, 150, 50),
			LDL::Color(255, 255, 100),
			LDL::Color(100, 255, 100),
			LDL::Color(100, 150, 255),
			LDL::Color(150, 100, 255),
			LDL::Color(255, 100, 255),
			LDL::Color(255, 150, 150),
			LDL::Color(200, 200, 100),
			LDL::Color(100, 200, 200)
		},
		// Ледяной синий
		{
			LDL::Color(200, 230, 255),
			LDL::Color(150, 210, 255),
			LDL::Color(100, 190, 255),
			LDL::Color(50, 170, 255),
			LDL::Color(0, 150, 255),
			LDL::Color(0, 130, 220),
			LDL::Color(0, 100, 180),
			LDL::Color(0, 70, 140),
			LDL::Color(0, 50, 100),
			LDL::Color(0, 30, 60)
		},
		// Огненный
		{
			LDL::Color(255, 255, 150),
			LDL::Color(255, 230, 100),
			LDL::Color(255, 200, 50),
			LDL::Color(255, 170, 0),
			LDL::Color(255, 130, 0),
			LDL::Color(255, 90, 0),
			LDL::Color(220, 60, 0),
			LDL::Color(180, 30, 0),
			LDL::Color(130, 10, 0),
			LDL::Color(80, 0, 0)
		},
		// Неоновый фиолетовый
		{
			LDL::Color(255, 200, 255),
			LDL::Color(230, 150, 255),
			LDL::Color(200, 100, 255),
			LDL::Color(180, 50, 255),
			LDL::Color(150, 0, 255),
			LDL::Color(130, 0, 220),
			LDL::Color(100, 0, 180),
			LDL::Color(70, 0, 140),
			LDL::Color(50, 0, 100),
			LDL::Color(30, 0, 60)
		}
	};

	const int brightnessLevels = 10;

	// Создаем текстуры для всех символов, цветовых схем и уровней яркости
	std::vector<std::vector<std::vector<LDL::Texture*> > > allCharTextures;

	for (int scheme = 0; scheme < colorSchemeCount; scheme++)
	{
		std::vector<std::vector<LDL::Texture*> > schemeTextures;
		for (int c = 0; c < charsLength; c++)
		{
			std::vector<LDL::Texture*> brightnessTextures;
			char singleChar[2] = { rainChars[c], '\0' };

			for (int b = 0; b < brightnessLevels; b++)
			{
				float brightness = 1.0f - (float)b / brightnessLevels;
				LDL::Color charColor(
					(unsigned char)(schemeColors[scheme][b].r),
					(unsigned char)(schemeColors[scheme][b].g),
					(unsigned char)(schemeColors[scheme][b].b)
				);

				rasterizer.Text(&rainFont, charColor, singleChar);
				brightnessTextures.push_back(new LDL::Texture(result, context,
					rasterizer.GetPixelFormat(), rasterizer.GetSize(),
					rasterizer.GetPixels()));
			}
			schemeTextures.push_back(brightnessTextures);
		}
		allCharTextures.push_back(schemeTextures);
	}

	// Текстуры для белых "голов" символов
	std::vector<LDL::Texture*> whiteHeadTextures;
	for (int c = 0; c < charsLength; c++)
	{
		char singleChar[2] = { rainChars[c], '\0' };
		rasterizer.Text(&rainFont, LDL::Color(255, 255, 255), singleChar);
		whiteHeadTextures.push_back(new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels()));
	}

	// Текстуры для ярких голов (разные цвета)
	std::vector<std::vector<LDL::Texture*> > brightHeadTextures;
	for (int scheme = 0; scheme < colorSchemeCount; scheme++)
	{
		std::vector<LDL::Texture*> schemeHeads;
		for (int c = 0; c < charsLength; c++)
		{
			char singleChar[2] = { rainChars[c], '\0' };
			rasterizer.Text(&rainFont, LDL::Color(255, 255, 200), singleChar);
			schemeHeads.push_back(new LDL::Texture(result, context,
				rasterizer.GetPixelFormat(), rasterizer.GetSize(),
				rasterizer.GetPixels()));
		}
		brightHeadTextures.push_back(schemeHeads);
	}

	// Текстуры для названий схем
	std::vector<LDL::Texture*> schemeNameTextures;
	for (int i = 0; i < colorSchemeCount; i++)
	{
		rasterizer.Text(&titleFont, schemeColors[i][0], schemeNames[i]);
		schemeNameTextures.push_back(new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels()));
	}

	int windowWidth = 800;
	int windowHeight = 600;
	int columnWidth = 20;
	int maxColumns = windowWidth / columnWidth;

	// Текущая цветовая схема
	int currentScheme = 0;
	float schemeDisplayTimer = 2.0f;

	// Создаем колонки дождя
	std::vector<DropColumn> columns;
	for (int i = 0; i < maxColumns; i++)
	{
		DropColumn col;
		col.y = (float)randomRange(-windowHeight, 0);
		col.speed = 60.0f + randomFloat() * 150.0f;
		col.charIndex = rand() % charsLength;
		col.colorIndex = rand() % colorSchemeCount;
		col.x = i * columnWidth;
		col.glowTimer = randomFloat() * 3.0f;
		columns.push_back(col);
	}

	// Вспышки
	std::vector<FlashParticle> flashes;
	const int maxFlashes = 50;

	// LDL::Ticks
	unsigned int startTicks = LDL::Ticks();
	unsigned int lastTicks = startTicks;

	while (window.IsRunning() && result.IsOk())
	{
		unsigned int currentTicks = LDL::Ticks();
		float deltaTime = (currentTicks - lastTicks) / 1000.0f;
		float currentTime = (currentTicks - startTicks) / 1000.0f;
		lastTicks = currentTicks;

		schemeDisplayTimer -= deltaTime;

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
						col.speed = 60.0f + randomFloat() * 150.0f;
						col.charIndex = rand() % charsLength;
						col.colorIndex = rand() % colorSchemeCount;
						col.x = i * columnWidth;
						col.glowTimer = randomFloat() * 3.0f;
						columns.push_back(col);
					}
					maxColumns = newMaxColumns;
				}
			}
			else if (event.IsKeyPressed(LDL_KeySpace))
			{
				currentScheme = (currentScheme + 1) % colorSchemeCount;
				schemeDisplayTimer = 2.0f;
			}
		}

		// Обновление колонок
		for (size_t i = 0; i < columns.size(); i++)
		{
			columns[i].y += columns[i].speed * deltaTime;
			columns[i].glowTimer -= deltaTime;

			// Сброс колонки когда ушла за экран
			if (columns[i].y > windowHeight + 100)
			{
				columns[i].y = (float)randomRange(-200, -20);
				columns[i].speed = 60.0f + randomFloat() * 150.0f;
				columns[i].charIndex = rand() % charsLength;
				columns[i].colorIndex = rand() % colorSchemeCount;
				columns[i].glowTimer = randomFloat() * 3.0f;
			}

			// Случайная смена символа в колонке
			if (rand() % 100 < 5)
			{
				columns[i].charIndex = rand() % charsLength;
			}
		}

		// Создание вспышек
		if (rand() % 100 < 10 && (int)flashes.size() < maxFlashes)
		{
			FlashParticle flash;
			flash.x = randomFloat() * windowWidth;
			flash.y = randomFloat() * windowHeight;
			flash.life = randomFloat() * 0.5f + 0.2f;
			flash.maxLife = flash.life;
			flash.colorIndex = rand() % colorSchemeCount;
			flashes.push_back(flash);
		}

		// Обновление вспышек
		for (size_t i = 0; i < flashes.size(); i++)
		{
			flashes[i].life -= deltaTime;
		}

		// Удаление мертвых вспышек
		for (int i = (int)flashes.size() - 1; i >= 0; i--)
		{
			if (flashes[i].life <= 0)
			{
				flashes.erase(flashes.begin() + i);
			}
		}

		render.Begin();

		// Черный фон
		render.SetColor(LDL::Color(0, 0, 0));
		render.Clear();

		// Легкая текстура фона (цифровой шум)
		for (int i = 0; i < 50; i++)
		{
			int nx = randomRange(0, windowWidth - 1);
			int ny = randomRange(0, windowHeight - 1);
			render.SetColor(LDL::Color(0, 8, 0));
			render.Fill(LDL::Vec2i(nx, ny), LDL::Vec2i(1, 1));
		}

		// Отрисовка колонок дождя
		for (size_t i = 0; i < columns.size(); i++)
		{
			// Определяем схему для колонки (смешиваем с текущей)
			int scheme = (currentScheme > 0) ? columns[i].colorIndex : 0;

			// Хвост колонки
			for (int j = 0; j < brightnessLevels; j++)
			{
				int charIdx = (columns[i].charIndex + j) % charsLength;
				int yPos = (int)columns[i].y - j * 18;

				if (yPos < -20 || yPos > windowHeight + 20)
				{
					continue;
				}

				// Для текущей схемы используем её цвета
				int useScheme;
				if (currentScheme == 0)
				{
					useScheme = scheme;
				}
				else
				{
					useScheme = (j == 0) ? currentScheme : scheme;
				}

				if (j == 0)
				{
					// Голова - яркая
					render.Draw(brightHeadTextures[useScheme][charIdx],
						LDL::Vec2i(columns[i].x, yPos));
				}
				else
				{
					// Хвост - затухающий
					render.Draw(allCharTextures[useScheme][charIdx][j],
						LDL::Vec2i(columns[i].x, yPos));
				}
			}

			// Свечение головы
			if (columns[i].glowTimer > 0)
			{
				float glowAlpha = columns[i].glowTimer / 3.0f * 0.3f;
				int headY = (int)columns[i].y;

				render.SetColor(LDL::Color(
					(unsigned char)(schemeColors[scheme][0].r * glowAlpha),
					(unsigned char)(schemeColors[scheme][0].g * glowAlpha),
					(unsigned char)(schemeColors[scheme][0].b * glowAlpha)
				));
				render.Fill(LDL::Vec2i(columns[i].x - 3, headY - 3), LDL::Vec2i(26, 24));
			}
		}

		// Отрисовка вспышек
		for (size_t i = 0; i < flashes.size(); i++)
		{
			float lifeRatio = flashes[i].life / flashes[i].maxLife;
			float pulse = sinf(lifeRatio * 10.0f) * 0.5f + 0.5f;

			int radius = (int)(lifeRatio * 15 + 5);

			for (int dy = -radius; dy <= radius; dy++)
			{
				for (int dx = -radius; dx <= radius; dx++)
				{
					float dist = sqrtf((float)(dx * dx + dy * dy));
					if (dist < radius)
					{
						float alpha = (1.0f - dist / radius) * lifeRatio * pulse * 0.4f;
						int px = (int)flashes[i].x + dx;
						int py = (int)flashes[i].y + dy;

						if (px >= 0 && px < windowWidth && py >= 0 && py < windowHeight)
						{
							render.SetColor(LDL::Color(
								(unsigned char)(schemeColors[flashes[i].colorIndex][0].r * alpha),
								(unsigned char)(schemeColors[flashes[i].colorIndex][0].g * alpha),
								(unsigned char)(schemeColors[flashes[i].colorIndex][0].b * alpha)
							));
							render.Fill(LDL::Vec2i(px, py), LDL::Vec2i(1, 1));
						}
					}
				}
			}
		}

		// Название схемы (показывается при смене)
		if (schemeDisplayTimer > 0)
		{
			float alpha = schemeDisplayTimer > 1.5f ? 1.0f : schemeDisplayTimer / 1.5f;
			render.Draw(schemeNameTextures[currentScheme],
				LDL::Vec2i(windowWidth / 2 - 100, windowHeight / 2 - 20));
		}

		// Подсказка
		render.Draw(infoText, LDL::Vec2i(10, 10));

		// Информация о схеме
		char schemeText[100];
		sprintf(schemeText, "Mode: %s | Columns: %d",
			schemeNames[currentScheme], (int)columns.size());
		rasterizer.Text(&infoFont, LDL::Color(100, 100, 100), schemeText);
		LDL::Texture* schemeTexture = new LDL::Texture(result, context,
			rasterizer.GetPixelFormat(), rasterizer.GetSize(),
			rasterizer.GetPixels());
		render.Draw(schemeTexture, LDL::Vec2i(10, 25));
		delete schemeTexture;

		render.End();
	}

	// Очистка памяти
	delete infoText;

	for (size_t scheme = 0; scheme < allCharTextures.size(); scheme++)
	{
		for (size_t c = 0; c < allCharTextures[scheme].size(); c++)
		{
			for (size_t b = 0; b < allCharTextures[scheme][c].size(); b++)
			{
				delete allCharTextures[scheme][c][b];
			}
		}
	}

	for (size_t i = 0; i < whiteHeadTextures.size(); i++)
	{
		delete whiteHeadTextures[i];
	}

	for (size_t scheme = 0; scheme < brightHeadTextures.size(); scheme++)
	{
		for (size_t c = 0; c < brightHeadTextures[scheme].size(); c++)
		{
			delete brightHeadTextures[scheme][c];
		}
	}

	for (size_t i = 0; i < schemeNameTextures.size(); i++)
	{
		delete schemeNameTextures[i];
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}
