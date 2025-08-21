#ifndef Arcanum_Loaders_LocationLoader_hpp
#define Arcanum_Loaders_LocationLoader_hpp

#include <Arcanum/Objects/LocationCreator.hpp>
#include <Arcanum/Readers/XmlReader.hpp>

namespace Arcanum
{
	namespace Loaders
	{
		class LocationLoader
		{
		public:
			LocationLoader(Readers::XmlReader* xmlReader, Objects::LocationCreator* locationCreator);
			void Reset(const std::string& path);
		private:
			Readers::XmlReader*       _xmlReader;
			Objects::LocationCreator* _locationCreator;
			size_t                    _sceneryCount;
		};
	}
}

#endif    