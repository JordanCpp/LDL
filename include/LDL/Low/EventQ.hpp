#ifndef LDL_Low_RingBuf_hpp
#define LDL_Low_RingBuf_hpp

#include <LDL/Low/Types.hpp>
#include <LDL/Low/Event.hpp>

#define LDL_EventQueueMax (256)

class LDL_EventQueue
{
public:
	LDL_EventQueue();
	bool IsEmpty();
	bool IsFull();
	size_t NextPosition(size_t position);
	bool Dequeue(LDL_Event& element);
	void Enqueue(const LDL_Event& element);
private:
	LDL_Event _Content[LDL_EventQueueMax];
	size_t _Head;
	size_t _Tail;
	size_t _Length;
	size_t _Capacity;
};

#endif
