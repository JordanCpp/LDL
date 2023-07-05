#include <LDL/Time/Ticks.hpp>
#include <unistd.h>
#include <time.h>

size_t LDL::Time::Ticks()
{
	size_t result = 0;

	timespec ts;

	clock_gettime(CLOCK_REALTIME, &ts);
	
	result = ts.tv_nsec / 1000000;
	result += ts.tv_sec * 1000;

	return result;
}

void LDL::Time::Delay(size_t count)
{
	if (count >= 1000)
		sleep(count / 1000);

	usleep((count % 1000) * 1000);
}