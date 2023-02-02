#include <Disciples/Game/Engine.hpp>

using namespace Disciples::Game;
using namespace LDL::Graphics;
using namespace LDL::Allocators;

Engine::Engine(Settings* settings) :
	_Settings(settings),
	_ImageAllocator(Allocator::Mb * 2),
	_ImageLoader(&_ImageAllocator),
	_Window(Point2u(0,0), _Settings->Size(), _Settings->Title()),
	_Render(&_Window),
	_FpsLimiter(_Settings->Fps())
{
}

void Engine::Run()
{
	LDL::Events::Event report = { 0 };

	while (_Window.GetEvent(report))
	{
		_FpsLimiter.Mark();
		_FpsCounter.Start();

		if (report.Type == LDL::Events::IsQuit)
		{
			_Window.StopEvent();
		}

		_Render.Begin();
		_Render.End();

		_FpsLimiter.Throttle();

		if (_FpsCounter.Calc())
		{
			_Title = _Settings->Title() + " Fps: " + _Convert.Convert(_FpsCounter.Fps());
			_Window.Title(_Title);
			_FpsCounter.Clear();
		}
	}
}