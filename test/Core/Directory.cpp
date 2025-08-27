// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/Directory.hpp>

using namespace LDL;

void Open()
{
	Result result;
	Directory directory(result);

	LDL_TEST_EQUAL(directory.Open("*") == true);
	LDL_TEST_EQUAL(directory.Open("blabla") == false);
}

void Next()
{
	Result result;
	Directory directory(result);

	if (directory.Open("*"))
	{
		FileInfo fileInfo;

		while (directory.Next(fileInfo))
		{
			LDL_TEST_EQUAL(LDL::strlen(fileInfo.Name()) > 0);
		}
	}
}

void Create()
{
	Result result;
	Directory directory(result);

	LDL_TEST_EQUAL(directory.Create("TestFiles/Test") == true);
	LDL_TEST_EQUAL(directory.Create("TestFiles/Test") == false);
}

void Exist()
{
	Result result;
	Directory directory(result);

	LDL_TEST_EQUAL(directory.DirExist("TestFiles/Test") == true);
}

void Delete()
{
	Result result;
	Directory directory(result);

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
