
#include <SDL3/SDL_events.h>
#include "SDL_Application.hpp"

bool SDL_PollEvent(SDL_Event* event)
{
	if (App().PollEvent(*event))
	{
		return true;
	}

	App().PollEvents();

	return false;
}
