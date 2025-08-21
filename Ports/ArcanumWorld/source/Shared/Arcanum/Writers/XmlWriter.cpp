#include <Arcanum/Writers/XmlWriter.hpp>

using namespace Arcanum::Writers;

XmlWriter::~XmlWriter()
{
	Close();
}

bool XmlWriter::Reset(const std::string& path)
{
	Close();

	_file.open(path, std::ios::trunc);

	return _file.is_open();
}

void XmlWriter::Close()
{
	_file.close();
}

void XmlWriter::TagBegin(const std::string& name)
{
	_file << "<" << name << ">" << '\n';
}

void XmlWriter::TagEnd(const std::string& name)
{
	_file << "</" << name << ">" << '\n';
}

void XmlWriter::Node(const std::string& name, const std::string& data)
{
	_file << "<" << name << ">" << data << "</" << name << ">" << '\n';
}

void XmlWriter::Node(const std::string& name, intmax_t data)
{
	Node(name, _convert.ToString(data));
}
