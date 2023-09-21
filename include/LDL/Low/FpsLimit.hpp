#ifndef LDL_Low_FpsLimit_hpp
#define LDL_Low_FpsLimit_hpp

#include <LDL/Low/Types.hpp>

class LDL_FpsLimiter
{
public:
	LDL_FpsLimiter(size_t fps = 60);
	void Mark();
	void Throttle() const;
private:
	size_t _Fps;
	size_t _Ticks;
};

#endif    
