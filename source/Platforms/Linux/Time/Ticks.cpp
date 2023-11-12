#include <LDL/Time/Ticks.hpp>
#include <unistd.h>
#include <sys/time.h>

size_t LDL::Time::Ticks()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void LDL::Time::Delay(size_t count)
{
	if (count >= 1000)
		sleep(count / 1000);

	usleep((count % 1000) * 1000);
}