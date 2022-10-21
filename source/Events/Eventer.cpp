#include <LDL/Events/Eventer.hpp>

LDL::Events::Eventer::Eventer() :
	_Running(true)
{
}

void LDL::Events::Eventer::Push(LDL::Events::Event& event)
{
	_Queue.push(event);
}

bool LDL::Events::Eventer::Pop(LDL::Events::Event& event)
{
    if (!_Queue.empty())
    {
        event = _Queue.front();
        _Queue.pop();

        return true;
    }

    return false;
}

bool LDL::Events::Eventer::Running()
{
	return _Running;
}

void LDL::Events::Eventer::Stop()
{
	_Running = false;
}