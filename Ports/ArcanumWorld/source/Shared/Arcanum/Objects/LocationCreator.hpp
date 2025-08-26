// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Objects_LocationCreator_hpp
#define Arcanum_Objects_LocationCreator_hpp

#include <Arcanum/Objects/LocationData.hpp>
#include <Arcanum/Managers/ObjectManager.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class LocationCreator
		{
		public:
			LocationCreator(LocationData * locationData, Managers::ObjectManager* objectManager);
			void Reset(const LDL::Math::Vec2u& size);
			void NewTile(size_t index, const std::string& path);
			Scenery* NewScenery(const LDL::Math::Vec2u& pos, const std::string& path);
		private:
			LocationData* _LocationData;
			Managers::ObjectManager* _ObjectManager;
		};
	}
}

#endif