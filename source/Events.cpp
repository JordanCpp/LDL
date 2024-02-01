/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include <LDL/Events.hpp>
#include <string.h>
/********************************************************************************************************************************
													         LDL_EventQueue
********************************************************************************************************************************/
LDL_EventQueue::LDL_EventQueue() :
	_Head(-1),
	_Tail(0),
	_Length(0),
	_Capacity(Max)
{
	memset(_Content, 0, sizeof(_Content));
}

bool LDL_EventQueue::IsEmpty()
{
	return _Length == 0;
}

bool LDL_EventQueue::IsFull()
{
	return _Length == _Capacity;
}

size_t LDL_EventQueue::NextPosition(size_t position)
{
	return (position + 1) % _Capacity;
}

bool LDL_EventQueue::Dequeue(LDL_Event& element)
{
	if (!IsEmpty())
	{
		element = _Content[_Tail];
		_Tail = NextPosition(_Tail);
		_Length--;

		return true;
	}

	return false;
}

void LDL_EventQueue::Enqueue(const LDL_Event& element)
{
	_Head = NextPosition(_Head);

	_Content[_Head] = element;

	if (IsFull())
		_Tail = NextPosition(_Tail);
	else
		_Length++;
}
/********************************************************************************************************************************
													         LDL_Eventer
********************************************************************************************************************************/
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