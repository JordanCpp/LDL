#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/Directory.hpp>

void Open()
{
	LDL::Core::Directory directory;

	LDL_TEST_EQUAL(directory.Open("*") == true);
	LDL_TEST_EQUAL(directory.Open("blabla") == false);
}

void Next()
{
	LDL::Core::Directory directory;

	if (directory.Open("*"))
	{
		LDL::Core::FileInfo fileInfo;

		while (directory.Next(fileInfo))
		{
			LDL_TEST_EQUAL(fileInfo.Name().length() > 0);
		}
	}
}

void Create()
{
	LDL::Core::Directory directory;

	LDL_TEST_EQUAL(directory.Create("TestFiles/Test") == true);
	LDL_TEST_EQUAL(directory.Create("TestFiles/Test") == false);
}

void Exist()
{
	LDL::Core::Directory directory;

	LDL_TEST_EQUAL(directory.Exist("TestFiles/Test") == true);
}

void Delete()
{
	LDL::Core::Directory directory;

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