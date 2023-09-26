#ifndef LDL_Low_FpsCount_hpp
#define LDL_Low_FpsCount_hpp

#include <LDL/Low/Config.hpp>
#include <LDL/Low/Types.hpp>

class LDL_LIBRARY LDL_FpsCounter
{
public:
	LDL_FpsCounter();
	void Start();
	bool Calc();
	size_t Fps();
	void Clear();
private:
	size_t _Current;
	size_t _Delta;
	size_t _Old;
	size_t _Fps;
};

#endif     
