#ifndef LDL_Time_FpsCounter_hpp
#define LDL_Time_FpsCounter_hpp

#include <ctime>

namespace LDL
{
	namespace Time
	{
		class FpsCounter
		{
		public:
			FpsCounter();
			void Start();
			bool Calc();
			size_t Fps();
			void Clear();
		private:
			clock_t _Current;
			clock_t	_Delta;
			clock_t	_Old;
			clock_t _Fps;
		};
	}
}

#endif     