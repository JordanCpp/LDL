#include "Engine.hpp"

Game::Engine::Engine(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title) :
	_Allocator(LDL::Allocators::Allocator::Mb * 4),
	_ImageLoader(&_Allocator),
	_Window(pos, size, title),
	_Render(&_Window)
{
}

void Game::Engine::Run()
{
	LDL::Events::Event report = { 0 };

	while (_Window.GetEvent(report))
	{
		_FpsLimiter.Mark();
		_FpsCounter.Start();

		_Render.Begin();

		if (report.Type == LDL::Events::IsQuit)
		{
			_Window.StopEvent();
		}

		_Render.End();

		_FpsLimiter.Throttle();

		if (_FpsCounter.Calc())
		{
			if (_Convert.Convert(_FpsCounter.Fps()))
			{
				_Window.Title(_Convert.Result());
			}

			_FpsCounter.Clear();
		}
	}
}