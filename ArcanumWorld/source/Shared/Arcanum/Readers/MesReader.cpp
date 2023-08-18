#include <Arcanum/Readers/MesReader.hpp>
#include <Arcanum/Core/RuntimeError.hpp>

using namespace Arcanum::Core;
using namespace Arcanum::Readers;

void MesReader::Reset(const std::string& path)
{
	Close();

	_File.open(path, std::ios::in);

	if (!_File.is_open())
		throw RuntimeError("Can't open file: " + path);
}

void MesReader::Close()
{
	if (_File.is_open())
		_File.close();
}

char MesReader::NextChar()
{
	char result = _File.get();

	return result;
}

bool MesReader::Next()
{
	char ch = NextChar();

	while (isspace(ch))
		ch = NextChar();

	if (ch == '/')
	{
		while (ch != '\n')
			ch = NextChar();
	}

	if (Eof())
		return false;

	if (ch == '{')
	{
		ch = NextChar();

		while (ch != '}')
		{
			_Result.push_back(ch);
			ch = NextChar();
		}
	}

	return true;
}

const std::string&MesReader::Result()
{
	return _Result;
}

bool MesReader::Eof()
{
	return _File.eof();
}