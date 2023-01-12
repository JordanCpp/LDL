#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/ImageWritter.hpp>
#include <LDL/Allocators/FixedLinear.hpp>

using namespace LDL::Graphics;

const Point2u size = Point2u(640, 480);
const Point2u sz = Point2u(640, 480);

void Screen()
{
	/*
	Window window(Point2u(0, 0), size, __FILE__);
	Render render(&window);

	LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 4);
	
	LDL::Loaders::ImageLoader loader(&allocator);
	
	loader.Load("TestFiles/trehmachtovyiy-korabl-kartina-maslom-60x50_512x.jpg");
	
	Texture img(loader.Size(), loader.BytesPerPixel(), loader.Pixels());

	for (size_t i = 0; i < 10; i++)
	{
		render.Color(Color(237, 28, 36));
		render.Clear();
		render.Begin();
		render.Draw(&img, Point2u(0, 0), render.Size());
		render.End();
	}

	Surface image(render.Size(), 4);

	render.Buffer(image.Pixels());

	uint8_t* pixels = image.Pixels();

	ImageWritter writter;

	writter.Save("RenderScreen.png", render.Size(), 4, pixels);

	
	for (size_t i = 0; i < image.Size().PosX() * image.Size().PosY() * 4; i += 4)
	{
		LDL_TEST_EQUAL(pixels[i + 0] == 237);
		LDL_TEST_EQUAL(pixels[i + 1] == 28);
		LDL_TEST_EQUAL(pixels[i + 2] == 36);
	}
	*/
}

int main()
{
	Screen();

	return 0;
}