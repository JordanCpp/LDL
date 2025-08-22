
#include <LDL/Shared/Events/Eventer.hpp>

using namespace LDL;
using namespace Events;

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
	_queue.enqueue(event);
}

bool Eventer::Pop(Event& event)
{
    if (!_queue.empty())
    {
        _queue.dequeue(event);

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
