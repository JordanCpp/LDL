#include "Eventer.hpp"

using namespace LDL::Events;

Eventer::Eventer() :
	_running(true)
{
}

bool Eventer::Empty()
{
    return _queue.empty();
}

void Eventer::Push(Event& event)
{
	_queue.push(event);
}

bool Eventer::Pop(Event& event)
{
    if (!_queue.empty())
    {
        event = _queue.front();
        _queue.pop();

        return true;
    }

    return false;
}

bool Eventer::Running()
{
	return _running;
}

void Eventer::Stop()
{
	_running = false;
}
