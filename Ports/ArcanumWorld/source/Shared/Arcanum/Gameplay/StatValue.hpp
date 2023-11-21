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
				_Value(T()),
				_Number(T()),
				_Percent(T()),
				_Current(T())
			{
			}

			T Value()
			{
				return _Value;
			}

			void Value(T value)
			{
				_Value = value;
			}

			T Number()
			{
				return _Number;
			}

			void Number(T value)
			{
				_Number = value;
			}

			T Percent()
			{
				return _Percent;
			}

			void Percent(T value)
			{
				_Percent = value;
			}

			T Current()
			{
				return _Current;
			}

			void Current(T value)
			{
				_Current = value;
			}
		private:
			T _Value;
			T _Number;
			T _Percent;
			T _Current;
		};
	}
}

#endif    