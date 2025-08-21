#include <Arcanum/Readers/MemoryReader.hpp>
#include <string.h>

using namespace Arcanum::Readers;

MemoryReader::MemoryReader(ByteReader* byteReader) :
	_byteReader(byteReader),
	_offset(0)
{
}

void MemoryReader::Close()
{
	_byteReader->Close();
}

bool MemoryReader::Reset(const std::string& path)
{
	_offset = 0;
	bool result = _byteReader->Reset(path, ByteReader::BigEndian);

	_content.resize(_byteReader->Bytes());

	_byteReader->Read(&_content.front(), _byteReader->Bytes());

	return result;
}

bool MemoryReader::Reset(const std::vector<uint8_t>& data)
{
	_offset  = 0;
	_content = data;

	return true;
}

std::vector<uint8_t>& MemoryReader::Content()
{
	return _content;
}

void MemoryReader::Read(void* buffer, size_t bytes)
{
	memcpy(buffer, &_content[_offset], bytes);

	_offset += bytes;
}