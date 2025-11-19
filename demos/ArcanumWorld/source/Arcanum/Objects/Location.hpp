// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Objects_Location_hpp
#define Arcanum_Objects_Location_hpp

#include <Arcanum/Objects/LocationData.hpp>
#include <Arcanum/Managers/ObjectManager.hpp>
#include <Arcanum/Painters/LocationPainter.hpp>
#include <Arcanum/Objects/LocationCreator.hpp>

namespace Arcanum
{
	class Location
	{
	public:
		Location(LocationData* locationData, LocationCreator* locationCreator, LocationPainter* locationPainter);
		void Draw(const LDL_Vec2u& start);
		Scenery* NewScenery(const LDL_Vec2u& pos, const std::string& path);
		Tile* NewTile(const LDL_Vec2u& pos, const std::string& path);
	private:
		LocationData*    _locationData;
		LocationCreator* _locationCreator;
		LocationPainter* _locationPainter;
	};
}

#endif
