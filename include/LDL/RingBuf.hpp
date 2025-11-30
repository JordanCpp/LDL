// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_RingBuf_hpp
#define LDL_RingBuf_hpp

#include <LDL/PVector.hpp>

template<class T>
class LDL_RingBuffer
{
public:
    LDL_RingBuffer(size_t capacity = 1024) :
        _head(capacity > 0 ? capacity - 1 : 0),
        _tail(0),
        _length(0),
        _capacity(capacity)
    {
        if (capacity > 0)
        {
            _content.resize(capacity);
        }
    }

    bool empty() const
    {
        return _length == 0;
    }

    bool full() const
    {
        return _length == _capacity;
    }

    size_t size() const
    {
        return _length;
    }

    size_t capacity() const
    {
        return _capacity;
    }

    size_t next(size_t pos) const
    {
        return (pos + 1) % _capacity;
    }

    bool dequeue(T& element)
    {
        if (!empty())
        {
            element = _content[_tail];
            _tail = next(_tail);
            _length--;

            return true;
        }

        return false;
    }

    void enqueue(const T& element)
    {
        if (_capacity == 0)
        {
            return;
        }

        _head = next(_head);
        _content[_head] = element;

        if (full())
        {
            _tail = next(_tail);
        }
        else
        {
            _length++;
        }
    }

    T* front()
    {
        return empty() ? NULL : &_content[_tail];
    }

    const T* front() const
    {
        return empty() ? NULL : &_content[_tail];
    }

    bool peek(T& element) const
    {
        if (!empty())
        {
            element = _content[_tail];

            return true;
        }

        return false;
    }

    void clear()
    {
        _head = _capacity > 0 ? _capacity - 1 : 0;
        _tail = 0;
        _length = 0;
    }

private:
    LDL_PodVector<T> _content;
    size_t           _head;
    size_t           _tail;
    size_t           _length;
    size_t           _capacity;
};

#endif
