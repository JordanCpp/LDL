#include <Arcanum/Readers/MesReader.hpp>
#include <Arcanum/Core/RuntimeError.hpp>

using namespace Arcanum;
using namespace Arcanum::Readers;

void MesReader::Reset(const std::string& path)
{
	Close();

	_file.open(path, std::ios::in);

	if (!_file.is_open())
		throw RuntimeError("Can't open file: " + path);
}

void MesReader::Close()
{
	if (_file.is_open())
		_file.close();
}

char MesReader::NextChar()
{
	char result = _file.get();

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
			_result.push_back(ch);
			ch = NextChar();
		}
	}

	return true;
}

const std::string&MesReader::Result()
{
	return _result;
}

bool MesReader::Eof()
{
	return _file.eof();
}