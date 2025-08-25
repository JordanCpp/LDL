// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/LDL.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_2.hpp>
#include <time.h>
#include <string.h>
#include <stdlib.h>

using namespace LDL::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Math;

void Identity()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

class TCell
{
public:
	bool mine;
	bool flag;
	bool open;
	int cntAround;
};

const int mapW = 10;
const int mapH = 10;

TCell map[mapW][mapH];

int mines;
int closedCell;

void GameNew()
{
	srand((uint32_t)time(NULL));
	memset(map, 0, sizeof(map));

	mines = 20;
	closedCell = mapW * mapH;

	for (int i = 0; i < mines; i++)
	{
		int x = rand() % mapW;
		int y = rand() % mapH;

		if (map[x][y].mine)
			i--;
		else
			map[x][y].mine = true;
	}
}

bool IsCellInMap(int x, int y)
{
	return (x >= 0) && (y >= 0) && (x < mapW) && (y < mapH);
}

void ShowMine()
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.7f, 0.3f);
	glVertex2f(0.7f, 0.7f);
	glVertex2f(0.3f, 0.7f);
	glEnd();
}

void ShowField()
{
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.8f, 0.8f, 0.8f); glVertex2f(0, 1);
	glColor3f(0.7f, 0.7f, 0.7f); glVertex2f(1, 1); glVertex2f(0, 0);
	glColor3f(0.6f, 0.6f, 0.6f); glVertex2f(1, 0);
	glEnd();
}

void GameShow()
{
	glScalef(2.0f / mapW, 2.0f / mapH, 1);
	glTranslatef(-mapW * 0.5f, -mapH * 0.5f, 0);

	for (int j = 0; j < mapH; j++)
	{
		for (int i = 0; i < mapW; i++)
		{
			glPushMatrix();

			glTranslatef((GLfloat)i, (GLfloat)j, 0);

			ShowField();

			if (map[i][j].mine)
				ShowMine();

			glPopMatrix();
		}
	}
}

void Display()
{
	Identity();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	GameShow();
}

int main()
{
	MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	Result result;
	RenderContext renderContext(RenderMode::OpenGL1);

	Window window(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
	Render render(result, renderContext, &window);

	Event report;

	FpsCounter fpsCounter;
	Convert convert;
	FpsLimiter fpsLimiter;

	GameNew();

	while (window.Running())
	{
		fpsLimiter.Mark();
		fpsCounter.Start();

		while (window.GetEvent(report))
		{
			if (report.Type == IsQuit)
			{
				window.StopEvent();
			}

			if (report.IsKeyPressed(KeyboardKey::Escape))
				window.StopEvent();
		}

		render.Begin();

		Display();

		render.End();

		fpsLimiter.Throttle();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));
			
		}

		
	}

	return 0;
}
