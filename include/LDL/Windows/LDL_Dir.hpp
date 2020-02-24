#ifndef _LDL_Dir_hpp_
#define _LDL_Dir_hpp_

#include <string>
#include <stdint.h> 
#include <windows.h>

namespace LDL
{

class DirElement
{
public:
  const std::string & Name();
  void Name(const char * Source);
  size_t Size();
  void Size(size_t Source);
private:
  size_t mSize;
  std::string mName;
};

void DirElement::Name(const char * Source)
{
  mName.assign(Source);
}

const std::string & DirElement::Name()
{
  return mName;
}

size_t DirElement::Size()
{
  return mSize;
}

void DirElement::Size(size_t Source)
{
  mSize = Source;
}

class Dir
{
public:
  bool Open(const std::string & Path, DirElement * Element);
  bool NextElement();
  ~Dir();
private:
  bool mIsOpen;
  DirElement * mElement;
  WIN32_FIND_DATA mData;
  HANDLE          mFile;
};

Dir::~Dir()
{
  if (mIsOpen)
  {
    FindClose(mFile);
  }
}

bool Dir::Open(const std::string & Path, DirElement * Element)
{
  mFile = FindFirstFile(Path.c_str(), &mData);

  if (mFile == INVALID_HANDLE_VALUE)
  {
    return false;
  }
  else
  {
    mElement = Element;
    mIsOpen  = true;

    return true;
  }
}

bool Dir::NextElement()
{
  if (FindNextFile(mFile, &mData))
  {
    mElement->Name(mData.cFileName);

    return true;
  }
  else
  {
    return false;
  } 
}

}

#endif