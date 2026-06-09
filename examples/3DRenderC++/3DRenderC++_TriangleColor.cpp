/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <LDL/C++98/LDL.hpp>

size_t fvf = LDL_FVF_XYZ | LDL_FVF_COLOR;

typedef struct
{
	float x, y, z;
	float r, g, b;
} Vertex;

Vertex data[] =
{
	{ 0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f},
	{-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f},
	{ 0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f}
};

int main()
{
	LDL::Result   result;
	LDL::Context  context(result);
	LDL::Event    event;
	LDL::Window   window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL 3D Render - Triangle", LDL_WindowModeResized);
	LDL::Render3D render(result, context, window);
	LDL::VertexBuffer vertexBuffer(context, fvf);

	vertexBuffer.Copy(sizeof(Vertex), 3, data);

	while (window.IsRunning() && result.IsOk())
	{
		while (window.GetEvent(event))
		{
			if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape))
			{
				window.StopEvent();
			}
		}

		render.Begin();

		render.Draw(&vertexBuffer);

		render.End();
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}
