#include <Arcanum/Readers/ByteReader.hpp>

using namespace Arcanum::Readers;

#define HTONS(n) (((((uint16_t)(n) & 0xFF)) << 8) | (((uint16_t)(n) & 0xFF00) >> 8))

#define HTONL(n) (((((uint32_t)(n) & 0xFF)) << 24) | \
                  ((((uint32_t)(n) & 0xFF00)) << 8) | \
                  ((((uint32_t)(n) & 0xFF0000)) >> 8) | \
                  ((((uint32_t)(n) & 0xFF000000)) >> 24)) 

bool ByteReader::Reset(const std::string & path, size_t type)
{
    if (_File.is_open())
        _File.close();

  _File.open(path.c_str(), std::ios::in | std::ios::binary);

  _Type = type;

  if (_File.is_open())
  {
      _File.seekg(0, std::ios::end);

      std::streampos length(_File.tellg());

      _File.seekg(0, std::ios::beg);

      _Bytes = (size_t)length;
  }

  return _File.is_open();
}

void ByteReader::Close()
{
    _File.close();
}

ByteReader::~ByteReader()
{
    Close();
}

size_t ByteReader::Bytes()
{
    return _Bytes;
}

void ByteReader::Pos(size_t value)
{
  _File.seekg(value, std::ios::beg);
}

void ByteReader::Read(void* buffer, size_t bytes)
{
    _File.read((char*)buffer, bytes);
}

bool ByteReader::Eof()
{
  return _File.good();
}

uint8_t ByteReader::u8()
{
  uint8_t val;

  _File.read((char*)&val, sizeof(uint8_t));

  return val;
}

uint16_t ByteReader::u16()
{
  uint16_t val;

  _File.read((char*)&val, sizeof(uint16_t));

  if (_Type == BigEndian)
      return val;
  else
      return HTONS(val);
}

int16_t ByteReader::i16()
{
  int16_t val;

  _File.read((char*)&val, sizeof(int16_t));

  if (_Type == BigEndian)
      return val;
  else
      return HTONS(val);
}

uint32_t ByteReader::u32()
{
  uint32_t val;

  _File.read((char*)&val, sizeof(uint32_t));
    
  if (_Type == BigEndian)
      return val;
  else
      return HTONL(val);
}

int32_t ByteReader::i32()
{
  int32_t val;

  _File.read((char*)&val, sizeof(int32_t));
    
  if (_Type == BigEndian)
      return val;
  else
      return HTONL(val);
}