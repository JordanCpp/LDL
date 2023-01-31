#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/Directory.hpp>

using namespace LDL::Core;

void Open()
{
	Directory directory;

	LDL_TEST_EQUAL(directory.Open("*") == true);
	LDL_TEST_EQUAL(directory.Open("blabla") == false);
}

void Next()
{
	Directory directory;

	if (directory.Open("*"))
	{
		FileInfo fileInfo;

		while (directory.Next(fileInfo))
		{
			LDL_TEST_EQUAL(fileInfo.Name().length() > 0);
		}
	}
}

void Create()
{
	Directory directory;

	LDL_TEST_EQUAL(directory.Create("TestFiles/Test") == true);
	LDL_TEST_EQUAL(directory.Create("TestFiles/Test") == false);
}

void Exist()
{
	Directory directory;

	LDL_TEST_EQUAL(directory.Exist("TestFiles/Test") == true);
}

void Delete()
{
	Directory directory;

	LDL_TEST_EQUAL(directory.Delete("TestFiles/Test") == true);
	LDL_TEST_EQUAL(directory.Delete("TestFiles/Test") == false);
}

int main()
{
	Open();
	Next();
	Create();
	Exist();
	Delete();

	return 0;
}