#ifndef LDL_Eventer_hpp
#define LDL_Eventer_hpp

#include <LDL/Low/EventQ.hpp>

class LDL_Eventer
{
public:
	LDL_Eventer();
	void Push(LDL_Event& event);
	bool Pop(LDL_Event& event);
	bool Running();
	void Stop();
	bool Empty();
private:
	bool _Running;
	LDL_EventQueue _Queue;
};


#endif
