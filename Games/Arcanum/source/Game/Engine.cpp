#include <Arcanum/Game/Engine.hpp>

using namespace Arcanum::Game;
using namespace LDL::Graphics;
using namespace LDL::Allocators;

Engine::Engine(Settings* settings) :
	_Settings(settings),
	_PathManager(settings->Path()),
	_ImageAllocator(Allocator::Mb * 2),
	_ImageLoader(&_ImageAllocator),
	_Window(Point2u(0,0), _Settings->Size(), _Settings->Title()),
	_Render(&_RenderContext, &_Window),
	_FpsLimiter(_Settings->Fps())
{
	_ArtFile.LoadArt("data/art/scenery/engine.ART");

	size_t w = _ArtFile.frame_data[0].header.width;
	size_t h = _ArtFile.frame_data[0].header.height;
	uint8_t* pixels = new uint8_t[w * h * 4];

	for (size_t y = 0; y < h; y++)
	{
		for (size_t x = 0; x < w; x++)
		{
			size_t index = ((w * y) + x) * 4;

			ArtTable& ap = _ArtFile.palette_data[0];

			uint8_t c = _ArtFile.frame_data[0].GetValue(x, y);

			uint8_t r = ap.colors[c].r;
			uint8_t g = ap.colors[c].g;
			uint8_t b = ap.colors[c].b;

			if (c != 0)
			{
				pixels[index + 0] = r;
				pixels[index + 1] = g;
				pixels[index + 2] = b;
				pixels[index + 3] = 255;
			}
			else
			{
				pixels[index + 0] = 0;
				pixels[index + 1] = 0;
				pixels[index + 2] = 0;
				pixels[index + 3] = 0;
			}
		}
	}
	
	_Texture = new Texture(&_RenderContext, Point2u(w, h), (uint8_t*)pixels, 4);
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

		_Render.Color(Color(255, 5, 255));
		_Render.Clear();
		
		_Render.Draw(_Texture, Point2u(0, 0));

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