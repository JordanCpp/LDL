// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_PVector_hpp
#define LDL_PVector_hpp

#include <LDL/New.hpp>
#include <LDL/Assert.hpp>
#include <LDL/StdFuncs.hpp>

template <class T>
class LDL_PodVector
{
private:
    T*      _data;
    size_t  _size;
    size_t  _capacity;

    void Reallocate(size_t newCapacity)
    {
        if (newCapacity <= _capacity)
        {
            return;
        }

        T* newData = (T*)LDL_malloc(newCapacity * sizeof(T));

        if (_data != NULL && _size > 0)
        {
            LDL_memcpy(newData, _data, _size * sizeof(T));
            LDL_free(_data);
        }

        _data     = newData;
        _capacity = newCapacity;
    }

    void FreeMemory()
    {
        if (_data != NULL)
        {
            LDL_free(_data);
            _data = NULL;
        }

        _size     = 0;
        _capacity = 0;
    }

public:
    LDL_PodVector() :
        _data(NULL), _size(0), _capacity(0)
    {
    }

    ~LDL_PodVector()
    {
        FreeMemory();
    }

    LDL_PodVector(const LDL_PodVector& other) :
        _data(NULL), _size(0), _capacity(0)
    {
        if (other._size > 0)
        {
            Reallocate(other._size);
            LDL_memcpy(_data, other._data, other._size * sizeof(T));
            _size = other._size;
        }
    }

    LDL_PodVector& operator=(const LDL_PodVector& other)
    {
        if (this != &other)
        {
            FreeMemory();

            if (other._size > 0)
            {
                Reallocate(other._size);
                LDL_memcpy(_data, other._data, other._size * sizeof(T));
                _size = other._size;
            }
        }

        return *this;
    }

    void push_back(const T& element)
    {
        if (_size == _capacity)
        {
            size_t newCapacity = _capacity == 0 ? 1 : _capacity * 2;
            Reallocate(newCapacity);
        }

        _data[_size] = element;
        ++_size;
    }

    void reserve(size_t count)
    {
        Reallocate(count);
    }

    void resize(size_t count)
    {
        if (count > _capacity)
        {
            Reallocate(count);
        }
        _size = count;
    }

    void clear()
    {
        _size = 0;
    }

    T& operator[](size_t index)
    {
        LDL_ASSERT_DETAIL(index < _size, "Index out of bounds");
        return _data[index];
    }

    const T& operator[](size_t index) const
    {
        LDL_ASSERT_DETAIL(index < _size, "Index out of bounds");
        return _data[index];
    }

    T& at(size_t index)
    {
        LDL_ASSERT_DETAIL(index < _size, "Index out of bounds");
        return _data[index];
    }

    const T& at(size_t index) const
    {
        LDL_ASSERT_DETAIL(index < _size, "Index out of bounds");
        return _data[index];
    }

    T& front()
    {
        LDL_ASSERT(_size > 0);
        return _data[0];
    }

    const T& front() const
    {
        LDL_ASSERT(_size > 0);
        return _data[0];
    }

    T& back()
    {
        LDL_ASSERT(_size > 0);
        return _data[_size - 1];
    }

    const T& back() const
    {
        LDL_ASSERT(_size > 0);
        return _data[_size - 1];
    }

    T* data()
    {
        return _data;
    }

    const T* data() const
    {
        return _data;
    }

    size_t size() const
    {
        return _size;
    }

    size_t capacity() const
    {
        return _capacity;
    }

    bool empty() const
    {
        return _size == 0;
    }
};

#endif
