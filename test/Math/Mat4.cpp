#include <LDL/Core/TestEqual.hpp>
#include <LDL/Math/Mat4.hpp>

using namespace LDL::Math;

void Default()
{
	Mat4f mat;
}

void Multiply()
{
	Mat4f mat1;
	Mat4f mat2;

	Mat4f mat3 = mat1 * mat2;
}

int main()
{
	Default();
	Multiply();

	return 0;
}
