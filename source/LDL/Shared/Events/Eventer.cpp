// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

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
