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
			Readers::XmlReader* _XmlReader;
			Objects::LocationCreator* _LocationCreator;
			size_t _SceneryCount;
		};
	}
}

#endif    