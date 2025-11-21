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

    void* alloc(size_t bytes)
    {
        return LDL_malloc(bytes);
    }

    void dealloc(void* ptr)
    {
        LDL_free(ptr);
    }

public:
    LDL_PodVector() :
        _data(0), _size(0), _capacity(0)
    {
    }

    ~LDL_PodVector()
    {
        dealloc(_data);
    }

    LDL_PodVector(const LDL_PodVector& other) :
        _data(0), _size(0), _capacity(0)
    {
        if (other._size == 0)
        {
            return;
        }

        reserve(other._size);

        for (size_t i = 0; i < other._size; ++i)
        {
            new (&_data[i]) T(other._data[i]);
        }

        _size = other._size;
    }

    LDL_PodVector& operator=(const LDL_PodVector& other)
    {
        if (this == &other)
        {
            return *this;
        }

        if (_capacity < other._size)
        {
            dealloc(_data);

            _data = 0;
            _capacity = 0;

            if (other._size > 0)
            {
                _data = (T*)alloc(other._size * sizeof(T));
                _capacity = other._size;
            }
        }

        _size = 0;

        for (size_t j = 0; j < other._size; ++j)
        {
            new (&_data[j]) T(other._data[j]);
            ++_size;
        }

        return *this;
    }

    void push_back(const T& element)
    {
        if (_size == _capacity)
        {
            reserve(_capacity == 0 ? 1 : _capacity * 2);
        }

        new (&_data[_size]) T(element);
        ++_size;
    }

    void reserve(size_t count)
    {
        if (count <= _capacity)
        {
            return;
        }

        T* new_data = (T*)alloc(count * sizeof(T));

        for (size_t i = 0; i < _size; ++i)
        {
            new (&new_data[i]) T(_data[i]);
        }

        dealloc(_data);
        _data = new_data;
        _capacity = count;
    }

    void resize(size_t count)
    {
        if (count > _capacity)
        {
            reserve(count);
        }

        while (_size < count)
        {
            new (&_data[_size]) T();
            ++_size;
        }
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
        return _data[0];
    }

    const T& front() const
    {
        return _data[0];
    }

    T& back()
    {
        return _data[_size - 1];
    }

    const T& back() const
    {
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
