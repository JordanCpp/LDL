#include <Arcanum/Writters/XmlWritter.hpp>

using namespace Arcanum::Writters;

XmlWritter::~XmlWritter()
{
	Close();
}

bool XmlWritter::Reset(const std::string& path)
{
	Close();

	_File.open(path, std::ios::trunc);

	return _File.is_open();
}

void XmlWritter::Close()
{
	_File.close();
}

void XmlWritter::TagBegin(const std::string& name)
{
	_File << "<" << name << ">" << '\n';
}

void XmlWritter::TagEnd(const std::string& name)
{
	_File << "</" << name << ">" << '\n';
}

void XmlWritter::Node(const std::string& name, const std::string& data)
{
	_File << "<" << name << ">" << data << "</" << name << ">" << '\n';
}

void XmlWritter::Node(const std::string& name, intmax_t data)
{
	Node(name, _NumberToString.ToString(data));
}