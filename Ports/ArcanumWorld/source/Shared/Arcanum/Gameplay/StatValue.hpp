// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Gameplay_StatValue_hpp
#define Arcanum_Gameplay_StatValue_hpp

namespace Arcanum
{
	namespace Gameplay
	{
		template <typename T>
		class StatValue
		{
		public:
			StatValue() :
				_value(T()),
				_number(T()),
				_percent(T()),
				_current(T())
			{
			}

			T Value()
			{
				return _value;
			}

			void Value(T value)
			{
				_value = value;
			}

			T Number()
			{
				return _number;
			}

			void Number(T value)
			{
				_number = value;
			}

			T Percent()
			{
				return _percent;
			}

			void Percent(T value)
			{
				_percent = value;
			}

			T Current()
			{
				return _current;
			}

			void Current(T value)
			{
				_current = value;
			}
		private:
			T _value;
			T _number;
			T _percent;
			T _current;
		};
	}
}

#endif    