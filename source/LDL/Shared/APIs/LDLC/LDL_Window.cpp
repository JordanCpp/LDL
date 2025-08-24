#include <LDLC/LDL_Window.h>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Shared/APIs/LDLC/LDL_RenderContext.hpp>
#include <string.h>

using namespace LDL::Core;
using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Math;

struct LDL_Window
{
	Result _result;
	Window _window;
	LDL_Window(LDL_RenderContext* renderContext, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode);
};

LDL_Window::LDL_Window(LDL_RenderContext* renderContext, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode) :
	_window(_result, renderContext->_renderContext, pos, size, title, mode)
{
}

LDL_Window* LDL_WindowNew(LDL_RenderContext* renderContext, size_t x, size_t y,size_t w, size_t h, const char * title, size_t mode)
{
	LDL_Window* p = new LDL_Window(renderContext, Vec2u(x, y), Vec2u(w, h), title, mode);

	return p;
}

void LDL_WindowFree(LDL_Window* window)
{
	delete window;
}

bool LDL_WindowRunning(LDL_Window* window)
{
	return window->_window.Running();
}

bool LDL_WindowGetEvent(LDL_Window* window, LDL_Event* event)
{
	Event src;

	bool result = window->_window.GetEvent(src);

	memcpy(event, &src, sizeof(Event));

	return result;
}

bool LDL_WindowWaitEvent(LDL_Window* window, LDL_Event* event)
{
	Event src;

	bool result = window->_window.WaitEvent(src);

	memcpy(event, &src, sizeof(Event));

	return result;
}

void LDL_WindowStopEvent(LDL_Window* window)
{
	window->_window.StopEvent();
}

void LDL_WindowSetTitle(LDL_Window* window, const char* title)
{
	window->_window.Title(title);
}

const char* LDL_WindowGetTitle(LDL_Window* window)
{
	return window->_window.Title();
}

size_t LDL_WindowGetPosX(LDL_Window* window)
{
	return  window->_window.Pos().x;
}

size_t LDL_WindowGetPosY(LDL_Window* window)
{
	return  window->_window.Pos().y;
}

size_t LDL_WindowGetSizeX(LDL_Window* window)
{
	return window->_window.Size().x;
}

size_t LDL_WindowGetSizeY(LDL_Window* window)
{
	return window->_window.Size().y;
}
