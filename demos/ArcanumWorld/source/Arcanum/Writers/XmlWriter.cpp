// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Writers/XmlWriter.hpp>

using namespace Arcanum;

XmlWriter::~XmlWriter()
{
	Close();
}

bool XmlWriter::Reset(const std::string& path)
{
	Close();

	_file.open(path.c_str(), std::ios::trunc);

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
