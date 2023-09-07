#include <LDL/Low/String.hpp>
#include <stdlib.h>

LDL_String::LDL_String() :
	_Content(NULL),
	_Capacity(0),
	_Position(0)
{
}

LDL_String::LDL_String(const char* elements) :
	_Content(NULL),
	_Capacity(0),
	_Position(0)
{
	Assign(elements);
}

LDL_String::~LDL_String()
{
}

void LDL_String::Clear()
{
	_Position = 0;
}

const char* LDL_String::CStr()
{
	return _Content;
}

size_t LDL_String::Capacity()
{
	return _Capacity;
}

size_t LDL_String::Size()
{
	return _Position;
}

void LDL_String::Reserve(size_t count)
{
	if (count > Capacity())
	{
		_Capacity = count + 1;

		char* p = (char*)malloc(_Capacity);

		for (size_t i = 0; i < _Position; i++)
		{
			p[i] = _Content[i];
		}

		if (_Content != NULL)
		{
			free(_Content);
		}

		_Content = p;

		p[_Position] = '\0';
	}
}

void LDL_String::Resize(size_t count)
{
	Reserve(count);

	_Position = count;
	_Content[_Position] = '\0';

}

void LDL_String::Append(const char& element)
{
	if (_Capacity == 0)
	{
		Reserve(2);
	}
	else if (_Position + 1 >= _Capacity)
	{
		Reserve(_Capacity * 2);
	}

	_Content[_Position] = element;

	_Position++;

	_Content[_Position] = '\0';
}

void LDL_String::Append(const char* elements)
{
	size_t i = 0;

	while (elements[i] != '\0')
	{
		Append(elements[i]);

		i++;
	}
}

void LDL_String::Assign(const char* elements)
{
	Clear();

	Append(elements);
}