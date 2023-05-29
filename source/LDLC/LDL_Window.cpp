#include <LDLC/LDL_Window.h>
#include <LDL/Graphics/Window.hpp>
#include <string.h>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Math;

struct LDL_Window
{
	Window _Window;
	LDL_Window(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode);
};

LDL_Window::LDL_Window(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
	_Window(pos, size, title, mode)
{
}

LDL_Window* LDL_WindowNew(size_t x, size_t y,size_t w, size_t h, const char * title, size_t mode)
{
	LDL_Window* p = new LDL_Window(Vec2u(x, y), Vec2u(w, h), title, mode);

	return p;
}

void LDL_WindowFree(LDL_Window* window)
{
	delete window;
}

bool LDL_WindowRunning(LDL_Window* window)
{
	return window->_Window.Running();
}

void LDL_WindowPollEvents(LDL_Window* window)
{
	window->_Window.PollEvents();
}

bool LDL_WindowGetEvent(LDL_Window* window, LDL_Event* event)
{
	Event src;

	bool result = window->_Window.GetEvent(src);

	memcpy(event, &src, sizeof(Event));

	return result;
}

bool LDL_WindowWaitEvent(LDL_Window* window, LDL_Event* event)
{
	Event src;

	bool result = window->_Window.WaitEvent(src);

	memcpy(event, &src, sizeof(Event));

	return result;
}

void LDL_WindowStopEvent(LDL_Window* window)
{
	window->_Window.StopEvent();
}

void LDL_WindowSetTitle(LDL_Window* window, const char* title)
{
	window->_Window.Title(title);
}

const char* LDL_WindowGetTitle(LDL_Window* window)
{
	return window->_Window.Title().c_str();
}

size_t LDL_WindowGetPosX(LDL_Window* window)
{
	return  window->_Window.Pos().x;
}

size_t LDL_WindowGetPosY(LDL_Window* window)
{
	return  window->_Window.Pos().y;
}

size_t LDL_WindowGetSizeX(LDL_Window* window)
{
	return window->_Window.Size().x;
}

size_t LDL_WindowGetSizeY(LDL_Window* window)
{
	return window->_Window.Size().y;
}
