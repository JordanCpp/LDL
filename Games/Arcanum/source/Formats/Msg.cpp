#include <Arcanum/Formats/Msg.hpp>

using namespace Arcanum::Formats;

size_t Msg::Number()
{
	return _Number;
}

void Msg::Number(size_t value)
{
	_Number = value;
}

const std::string& Msg::Content()
{
	return _Content;
}

void Msg::Content(const std::string& value)
{
	_Content = value;
}