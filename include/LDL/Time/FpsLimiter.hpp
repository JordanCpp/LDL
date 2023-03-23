#ifndef LDL_Time_FpsLimiter_hpp
#define LDL_Time_FpsLimiter_hpp

#include <LDL/Config.hpp>
#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Time
	{
		class LDL_EXPORT FpsLimiter
		{
		public:
			FpsLimiter(size_t fps = 60);
			void Mark();
			void Throttle() const;
		private:
			size_t _Fps;
			size_t _Ticks;
		};
	}
}

#endif    