// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Eventer.hpp>

LDL_Eventer::LDL_Eventer() :
	_running(true)
{
}

bool LDL_Eventer::Empty()
{
    return _queue.empty();
}

void LDL_Eventer::Push(LDL_Event& event)
{
	_queue.enqueue(event);
}

bool LDL_Eventer::Pop(LDL_Event& event)
{
    if (!_queue.empty())
    {
        _queue.dequeue(event);

        return true;
    }

    return false;
}

bool LDL_Eventer::Running()
{
	return _running;
}

void LDL_Eventer::Stop()
{
	_running = false;
}
