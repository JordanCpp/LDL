#ifndef Arcanum_Savers_LocationSaver_hpp
#define Arcanum_Savers_LocationSaver_hpp

#include <Arcanum/Writters/XmlWritter.hpp>
#include <Arcanum/Objects/LocationData.hpp>

namespace Arcanum
{
    namespace Savers
    {
        class LocationSaver
        {
        public:
            LocationSaver(Writters::XmlWritter* xmlWritter);
            void Save(Objects::LocationData* locationData, const std::string& path);
        private:
            Writters::XmlWritter* _XmlWritter;
        };
    }
}

#endif