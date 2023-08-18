#include <Arcanum/Readers/MemoryReader.hpp>
#include <string.h>

using namespace Arcanum::Readers;

MemoryReader::MemoryReader(ByteReader* byteReader) :
	_Offset(0),
	_ByteReader(byteReader)
{
}

void MemoryReader::Close()
{
	_ByteReader->Close();
}

bool MemoryReader::Reset(const std::string& path)
{
	_Offset = 0;
	bool result = _ByteReader->Reset(path, ByteReader::BigEndian);

	_Content.resize(_ByteReader->Bytes());

	_ByteReader->Read(&_Content.front(), _ByteReader->Bytes());

	return result;
}

bool MemoryReader::Reset(const std::vector<uint8_t>& data)
{
	_Offset  = 0;
	_Content = data;

	return true;
}

std::vector<uint8_t>& MemoryReader::Content()
{
	return _Content;
}

void MemoryReader::Read(void* buffer, size_t bytes)
{
	memcpy(buffer, &_Content[_Offset], bytes);

	_Offset += bytes;
}