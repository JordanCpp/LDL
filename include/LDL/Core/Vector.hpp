// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_Vector_hpp
#define LDL_Core_Vector_hpp

#include <LDL/Core/new.hpp>
#include <LDL/Core/StdFuncs.hpp>
#include <LDL/Core/Assert.hpp>

namespace LDL
{
    template <class T>
    class Vector
    {
    private:
        char*  _storage;
        size_t _size;
        size_t _capacity;

        T* data_ptr()
        {
            return (T*)(_storage);
        }

        const T* data_ptr() const
        {
            return (const T*)(_storage);
        }

        void* alloc(size_t bytes)
        {
            return LDL::LDL_malloc(bytes);
        }

        void dealloc(void* ptr)
        {
            LDL::LDL_free(ptr);
        }

    public:
        Vector() : 
            _storage(0), _size(0), _capacity(0)
        {
        }

        ~Vector()
        {
            for (size_t i = 0; i < _size; ++i)
            {
                data_ptr()[i].~T();
            }

            dealloc(_storage);
        }

        Vector(const Vector& other) : 
            _storage(0), _size(0), _capacity(0)
        {
            if (other._size == 0)
            {
                return;
            }

            reserve(other._size);

            for (size_t i = 0; i < other._size; ++i)
            {
                new (&data_ptr()[i]) T(other.data_ptr()[i]);
            }

            _size = other._size;
        }

        Vector& operator=(const Vector& other)
        {
            if (this == &other)
            {
                return *this;
            }

            for (size_t i = 0; i < _size; ++i)
            {
                data_ptr()[i].~T();
            }


            if (_capacity < other._size)
            {
                dealloc(_storage);

                _storage  = 0;
                _capacity = 0;

                if (other._size > 0)
                {
                    _storage  = (char*)alloc(other._size * sizeof(T));
                    _capacity = other._size;
                }
            }

            _size = 0;

            for (size_t j = 0; j < other._size; ++j)
            {
                new (&data_ptr()[j]) T(other.data_ptr()[j]);
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

            new (&data_ptr()[_size]) T(element);
            ++_size;
        }

        void reserve(size_t count)
        {
            if (count <= _capacity)
            {
                return;
            }

            char* new_storage = (char*)alloc(count * sizeof(T));

            for (size_t i = 0; i < _size; ++i)
            {
                new (&reinterpret_cast<T*>(new_storage)[i]) T(data_ptr()[i]);
                data_ptr()[i].~T();
            }

            dealloc(_storage);
            _storage  = new_storage;
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
                new (&data_ptr()[_size]) T();
                ++_size;
            }

            while (_size > count)
            {
                data_ptr()[--_size].~T();
            }
        }

        void clear()
        {
            for (size_t i = 0; i < _size; ++i)
            {
                data_ptr()[i].~T();
            }

            _size = 0;
        }

        T& operator[](size_t index)
        {
            LDL_ASSERT_DETAIL(index < _size, "Index of bounds");

            return data_ptr()[index];
        }

        const T& operator[](size_t index) const
        {
            LDL_ASSERT_DETAIL(index < _size, "Index of bounds");

            return data_ptr()[index];
        }

        T& at(size_t index)
        {
            LDL_ASSERT_DETAIL(index < _size, "Index of bounds");

            return data_ptr()[index];
        }

        const T& at(size_t index) const
        {
            LDL_ASSERT_DETAIL(index < _size, "Index of bounds");

            return data_ptr()[index];
        }

        T& front()
        {
            return data_ptr()[0];
        }

        const T& front() const
        {
            return data_ptr()[0];
        }

        T& back()
        {
            return data_ptr()[_size - 1];
        }

        const T& back() const
        {
            return data_ptr()[_size - 1];
        }

        T* data()
        {
            return data_ptr();
        }

        const T* data() const
        {
            return data_ptr();
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
}

#endif
