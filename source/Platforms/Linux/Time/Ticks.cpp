#include <LDL/Time/Ticks.hpp>
#include <unistd.h>
#include <time.h>

size_t LDL::Time::Ticks()
{
	struct timespec ts;
	unsigned theTick = 0U;
	clock_gettime(CLOCK_REALTIME, &ts);
	theTick = ts.tv_nsec / 1000000;
	theTick += ts.tv_sec * 1000;

	return theTick;
}

void LDL::Time::Delay(size_t count)
{
	if (count >= 1000)
		sleep(count / 1000);

	usleep((count % 1000) * 1000);
}