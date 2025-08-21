#ifndef Arcanum_Savers_LocationSaver_hpp
#define Arcanum_Savers_LocationSaver_hpp

#include <Arcanum/Writers/XmlWriter.hpp>
#include <Arcanum/Objects/LocationData.hpp>

namespace Arcanum
{
    namespace Savers
    {
        class LocationSaver
        {
        public:
            LocationSaver(Writers::XmlWriter* xmlWriter);
            void Save(Objects::LocationData* locationData, const std::string& path);
        private:
            Writers::XmlWriter* _xmlWriter;
        };
    }
}

#endif