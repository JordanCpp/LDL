#ifndef Arcanum_Formats_Sec_hpp
#define Arcanum_Formats_Sec_hpp

#include <stdint.h>
#include <vector>

namespace Arcanum
{
	namespace Formats
	{
		struct Light
		{
			uint8_t data[48];
		};

		struct TileScript
		{
			uint32_t unknown1;
			uint16_t index;
			uint16_t unknown2;
			uint32_t flags;
			uint32_t counters;
			uint32_t scriptId;
			uint32_t unknown3;
		};

		struct Sec
		{
			enum
			{
				MaxTiles = 4096,
				MaxRoffs = 256
			};
			Sec();
			uint32_t lights_count;
			std::vector<Light> lights;
			std::vector<uint32_t> tiles;
			std::vector<uint32_t> roofs;
		};
	}
}

#endif