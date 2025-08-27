// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Savers_LocationSaver_hpp
#define Arcanum_Savers_LocationSaver_hpp

#include <Arcanum/Writers/XmlWriter.hpp>
#include <Arcanum/Objects/LocationData.hpp>

namespace Arcanum
{
    class LocationSaver
    {
    public:
        LocationSaver(XmlWriter* xmlWriter);
        void Save(LocationData* locationData, const std::string& path);
    private:
        XmlWriter* _xmlWriter;
    };
}

#endif
