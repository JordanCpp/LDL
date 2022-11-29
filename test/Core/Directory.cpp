#include <LDL/Core/TestEqual.hpp>
#include <LDL/Creators/CoreCreator.hpp>

void Open()
{
	LDL::Creators::CoreCreator coreCreator;

	LDL::Core::IDirectory* directory = coreCreator.CreateDir();

	LDL_TEST_EQUAL(directory->Open("*") == true);
	LDL_TEST_EQUAL(directory->Open("blabla") == false);
}

void Next()
{
	LDL::Creators::CoreCreator coreCreator;

	LDL::Core::IDirectory* directory = coreCreator.CreateDir();

	if (directory->Open("*"))
	{
		LDL::Core::FileInfo fileInfo;

		while (directory->Next(fileInfo))
		{
			LDL_TEST_EQUAL(fileInfo.Name().length() > 0);
		}
	}
}

void Create()
{
	LDL::Creators::CoreCreator coreCreator;

	LDL::Core::IDirectory* directory = coreCreator.CreateDir();

	LDL_TEST_EQUAL(directory->Create("TestFiles/Test") == true);
	LDL_TEST_EQUAL(directory->Create("TestFiles/Test") == false);
}

void Exist()
{
	LDL::Creators::CoreCreator coreCreator;

	LDL::Core::IDirectory* directory = coreCreator.CreateDir();

	LDL_TEST_EQUAL(directory->Exist("TestFiles/Test") == true);
}

void Delete()
{
	LDL::Creators::CoreCreator coreCreator;

	LDL::Core::IDirectory* directory = coreCreator.CreateDir();

	LDL_TEST_EQUAL(directory->Delete("TestFiles/Test") == true);
	LDL_TEST_EQUAL(directory->Delete("TestFiles/Test") == false);
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