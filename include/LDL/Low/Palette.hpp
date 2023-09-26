#ifndef LDL_Low_Palette_hpp
#define LDL_Low_Palette_hpp

#include <LDL/Low/Config.hpp>
#include <LDL/Low/Color.hpp>

class LDL_LIBRARY LDL_Palette
{
public:
	LDL_Palette(size_t count);
	~LDL_Palette();
	size_t Count();
	LDL_Color* Colors();
	void Red(size_t index, uint8_t byte);
	void Green(size_t index, uint8_t byte);
	void Blue(size_t index, uint8_t byte);
private:
	size_t     _Count;
	LDL_Color* _Colors;
};

#endif
