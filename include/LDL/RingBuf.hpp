// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_RingBuf_hpp
#define LDL_RingBuf_hpp

#include <LDL/StdFuncs.hpp>
#include <LDL/PVector.hpp>

template<class T>
class LDL_RingBuffer
{
public:
	enum
	{
		COUNT = 1024
	};
	LDL_RingBuffer() :
		_head(COUNT - 1),
		_tail(0),
		_length(0),
		_capacity(COUNT)
	{
		_content.resize(COUNT);
	}

	bool empty()
	{
		return _length == 0;
	}

	bool full()
	{
		return _length == _capacity;
	}

	size_t next(size_t pos)
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

private:
	LDL_PodVector<T> _content;
	size_t           _head;
	size_t           _tail;
	size_t           _length;
	size_t           _capacity;
};

#endif
