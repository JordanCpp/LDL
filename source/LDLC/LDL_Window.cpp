#include <LDLC/LDL_Window.h>
#include <LDL/Graphics/Window.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;

struct LDL_Window
{
	Window _Window;
	LDL_Window(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode);
};

LDL_Window::LDL_Window(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode) :
	_Window(pos, size, title, mode)
{
}

LDL_Window* LDL_WindowNew(size_t x, size_t y,size_t w, size_t h, const char * title, size_t mode)
{
	LDL_Window* p = new LDL_Window(Point2u(x, y), Point2u(w, h), title, mode);

	return p;
}

void LDL_WindowFree(LDL_Window* window)
{
	delete window;
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
	return  window->_Window.Pos().PosX();
}

size_t LDL_WindowGetPosY(LDL_Window* window)
{
	return  window->_Window.Pos().PosY();
}

size_t LDL_WindowGetSizeX(LDL_Window* window)
{
	return window->_Window.Size().PosX();
}

size_t LDL_WindowGetSizeY(LDL_Window* window)
{
	return window->_Window.Size().PosY();
}
