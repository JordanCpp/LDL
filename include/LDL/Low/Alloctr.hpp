#ifndef LDL_Low_Alloctr_hpp
#define LDL_Low_Alloctr_hpp

#include <LDL/Low/Types.hpp>

class LDL_Allocator
{
public:
	enum
	{
		Kb = 1024, 
		Mb = Kb * 1024,
		Gb = Mb * 1024,
		Tb = Gb * 1024
	};
private:
	virtual void* Allocate(size_t bytes) = 0;
	virtual void Deallocate(void* ptr) = 0;
};

#endif
