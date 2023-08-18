#ifndef Arcanum_Objects_LocationLimits_hpp
#define Arcanum_Objects_LocationLimits_hpp

namespace Arcanum
{
	namespace Objects
	{
		class LocationLimits
		{
		public:
			enum
			{
				Tiles     = 100 * 100,
				Critters  = 1024,
				Sceneries = 2048,
				Walls     = 4096
			};
		private:
		};
	}
}

#endif