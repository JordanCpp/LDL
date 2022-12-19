#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/ImageWritter.hpp>
#include <LDL/Graphics/Cpu/CpuImage.hpp>
#include <LDL/Core/Directory.hpp>

using namespace LDL::Graphics;
using namespace LDL::Core;

const Point2u size = Point2u(640, 480);
const std::string path = "TestFiles/ImageWritterTest.png";

void Save()
{
	CpuImage image(Point2u(640, 480), 4);

	ImageWritter writter;

	writter.Save(path, size, 4, image.Pixels());

	Directory directory;

	LDL_TEST_EQUAL(directory.Exist(path) == true);

	directory.Remove(path);
}


int main()
{
	Save();

	return 0;
}