#include <LDL/Low/Eventer.hpp>

LDL_Eventer::LDL_Eventer() :
	_Running(true)
{
}

void LDL_Eventer::Push(LDL_Event& event)
{
	_Queue.Enqueue(event);
}

bool LDL_Eventer::Pop(LDL_Event& event)
{
    if (!_Queue.IsEmpty())
    {
        _Queue.Dequeue(event);

        return true;
    }

    return false;
}

bool LDL_Eventer::Running()
{
    return _Running;
}

void LDL_Eventer::Stop()
{
    _Running = false;
}

bool LDL_Eventer::Empty()
{
    return _Queue.IsEmpty();
}
