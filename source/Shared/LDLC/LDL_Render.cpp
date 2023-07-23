#include <LDLC/LDL_Render.h>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Texture.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

struct LDL_Render
{
	Render _Render;
	LDL_Render(LDL_RenderContext* renderContext, LDL_Window* window);
};

LDL_Render::LDL_Render(LDL_RenderContext* renderContext, LDL_Window* window) :
	_Render((RenderContext*)renderContext, (Window*)window)
{
}

LDL_Render* LDL_RenderNew(LDL_RenderContext* renderContext, LDL_Window* window)
{
	LDL_Render* p = new LDL_Render(renderContext, window);

	return p;
}

void LDL_RenderFree(LDL_Render* render)
{
	delete render;
}

void LDL_RenderBegin(LDL_Render* render)
{
	render->_Render.Begin();
}

void LDL_RenderEnd(LDL_Render* render)
{
	render->_Render.End();
}

size_t LDL_RenderGetSizeX(LDL_Render* render)
{
	return render->_Render.Size().x;
}

size_t LDL_RenderGetSizeY(LDL_Render* render)
{
	return render->_Render.Size().y;
}

void LDL_RenderClear(LDL_Render* render)
{
	render->_Render.Clear();
}

void LDL_RenderSetColor(LDL_Render* render, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	render->_Render.Color(Color(r, g, b, a));
}

void LDL_RenderFill(LDL_Render* render, size_t x, size_t y, size_t w, size_t h)
{
	render->_Render.Fill(Vec2u(x, y), Vec2u(w, h));
}

void LDL_RenderLine(LDL_Render* render, size_t x, size_t y, size_t w, size_t h)
{
	render->_Render.Line(Vec2u(x, y), Vec2u(w, h));
}

void LDL_RenderDrawTexture1(LDL_Render* render, LDL_Texture* texture, size_t x, size_t y)
{
	render->_Render.Draw((Texture*)texture, Vec2u(x, y));
}

void LDL_RenderDrawTexture2(LDL_Render* render, LDL_Texture* texture, size_t x, size_t y, size_t w, size_t h)
{
	render->_Render.Draw((Texture*)texture, Vec2u(x, y), Vec2u(w, h));
}

void LDL_RenderDrawTexture3(LDL_Render* render, LDL_Texture* texture, size_t dx, size_t dy, size_t x, size_t y, size_t w, size_t h)
{
	render->_Render.Draw((Texture*)texture, Vec2u(dx, dy), Vec2u(x, y), Vec2u(w, h));
}
