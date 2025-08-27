// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Readers/ByteReader.hpp>

using namespace Arcanum;

#define HTONS(n) (((((uint16_t)(n) & 0xFF)) << 8) | (((uint16_t)(n) & 0xFF00) >> 8))

#define HTONL(n) (((((uint32_t)(n) & 0xFF)) << 24) | \
                  ((((uint32_t)(n) & 0xFF00)) << 8) | \
                  ((((uint32_t)(n) & 0xFF0000)) >> 8) | \
                  ((((uint32_t)(n) & 0xFF000000)) >> 24)) 

bool ByteReader::Reset(const std::string & path, size_t type)
{
    if (_file.is_open())
        _file.close();

  _file.open(path.c_str(), std::ios::in | std::ios::binary);

  _type = type;

  if (_file.is_open())
  {
      _file.seekg(0, std::ios::end);

      std::streampos length(_file.tellg());

      _file.seekg(0, std::ios::beg);

      _bytes = (size_t)length;
  }

  return _file.is_open();
}

void ByteReader::Close()
{
    _file.close();
}

ByteReader::~ByteReader()
{
    Close();
}

size_t ByteReader::Bytes()
{
    return _bytes;
}

void ByteReader::Pos(size_t value)
{
  _file.seekg(value, std::ios::beg);
}

void ByteReader::Read(void* buffer, size_t bytes)
{
    _file.read((char*)buffer, bytes);
}

bool ByteReader::Eof()
{
  return _file.good();
}

uint8_t ByteReader::u8()
{
  uint8_t val;

  _file.read((char*)&val, sizeof(uint8_t));

  return val;
}

uint16_t ByteReader::u16()
{
  uint16_t val;

  _file.read((char*)&val, sizeof(uint16_t));

  if (_type == BigEndian)
      return val;
  else
      return HTONS(val);
}

int16_t ByteReader::i16()
{
  int16_t val;

  _file.read((char*)&val, sizeof(int16_t));

  if (_type == BigEndian)
      return val;
  else
      return HTONS(val);
}

uint32_t ByteReader::u32()
{
  uint32_t val;

  _file.read((char*)&val, sizeof(uint32_t));
    
  if (_type == BigEndian)
      return val;
  else
      return HTONL(val);
}

int32_t ByteReader::i32()
{
  int32_t val;

  _file.read((char*)&val, sizeof(int32_t));
    
  if (_type == BigEndian)
      return val;
  else
      return HTONL(val);
}
