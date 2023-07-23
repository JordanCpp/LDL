#include <LDL/Events/Eventer.hpp>

using namespace LDL::Events;

Eventer::Eventer() :
	_Running(true)
{
}

bool Eventer::Empty()
{
    return _Queue.empty();
}

void Eventer::Push(Event& event)
{
	_Queue.push(event);
}

bool Eventer::Pop(Event& event)
{
    if (!_Queue.empty())
    {
        event = _Queue.front();
        _Queue.pop();

        return true;
    }

    return false;
}

bool Eventer::Running()
{
	return _Running;
}

void Eventer::Stop()
{
	_Running = false;
}
