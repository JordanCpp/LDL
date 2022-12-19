#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Gpu/GpuWindow.hpp>
#include <LDL/Graphics/Gpu/GpuRender.hpp>
#include <LDL/Graphics/ImageWritter.hpp>
#include <LDL/Allocators/FixedLinear.hpp>

using namespace LDL::Graphics;

const Point2u size = Point2u(640, 480);
const Point2u sz = Point2u(640, 480);

void Screen()
{
	GpuWindow window(Point2u(0, 0), size, __FILE__);
	GpuRender render(&window);

	LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 4);
	LDL::Loaders::ImageLoader loader(&allocator);
	loader.Load("trehmachtovyiy-korabl-kartina-maslom-60x50_512x.jpg");
	GpuImage img(loader.Size(), loader.BytesPerPixel(), loader.Pixels());

	for (size_t i = 0; i < 10; i++)
	{
		render.Color(Color(237, 28, 36));
		render.Clear();
		render.Begin();
		render.Draw(&img, window.Pos(), render.Size());
		render.End();
	}

	CpuImage image(render.Size(), 4);

	render.Screen(image.Pixels());

	uint8_t* pixels = image.Pixels();

	ImageWritter writter;

	writter.Save("GpuRenderScreen.png", size, 4, pixels);

	for (size_t i = 0; i < image.Size().PosX() * image.Size().PosY() * 4; i += 4)
	{
		LDL_TEST_EQUAL(pixels[i + 0] == 237);
		LDL_TEST_EQUAL(pixels[i + 1] == 28);
		LDL_TEST_EQUAL(pixels[i + 2] == 36);
	}
}

int main()
{
	return 0;
}