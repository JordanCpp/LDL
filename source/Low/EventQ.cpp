#include <LDL/Low/EventQ.hpp>
#include <string.h>

LDL_EventQueue::LDL_EventQueue() :
	_Head(-1),
	_Tail(0),
	_Length(0),
	_Capacity(LDL_EventQueueMax)
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