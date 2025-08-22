// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef std_vector_hpp
#define std_vector_hpp

#include <stdlib.h>

namespace std
{
	template <typename T>
	class vector
	{
	private:
		T*     _data;
		size_t _size;
		size_t _capacity;

	public:
		vector() :
			_data(NULL),
			_size(0),
			_capacity(0)
		{
		}

		void push_back(const T& element)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}

			_data[_size++] = element;
		}

		size_t size() const
		{
			return _size;
		}

		void clear()
		{
			_size = 0;
		}

		void reserve(size_t count)
		{
			if (count > _capacity)
			{
				T* data = new T[count];

				for (size_t i = 0; i < _size; i++)
				{
					data[i] = _data[i];
				}

				delete _data;

				_data     = data;
				_capacity = count;
			}
		}

		void resize(size_t count)
		{
			if (count > _capacity)
			{
				reserve(count);
				
			}

			_size = count;
		}
		
		T& operator[] (size_t index)
		{
			return _data[index];
		}

		const T& operator[] (size_t index) const
		{
			return _data[index];
		}

		T& at(size_t index)
		{
			return _data[index];
		}

		const T& at(size_t index) const
		{
			return _data[index];
		}

		const T& back() const
		{
			return _data[_size - 1];
		}

		T& back()
		{
			return _data[_size - 1];
		}

		const T& front() const
		{
			return _data[0];
		}

		T& front()
		{
			return _data[0];
		}

		const T* data() const
		{
			return &_data[0];
		}

		T* data()
		{
			return &_data[0];
		}

		bool empty() const
		{
			return _size == 0;
		}
	};
}

#endif
