// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Managers_ObjectManager_hpp
#define Arcanum_Managers_ObjectManager_hpp

#include <Arcanum/Objects/Tile.hpp>
#include <Arcanum/Allocators/ObjectAllocator.hpp>
#include <Arcanum/Managers/SpriteManager.hpp>

namespace Arcanum
{
	class ObjectManager
	{
	public:
		ObjectManager(ObjectAllocator& objectAllocator, SpriteManager& spriteManager);
		Scenery* NewScenery(const std::string& name);
		void NewTile(Tile& object, const std::string& name);
	private:
		ObjectAllocator& _objectAllocator;
		SpriteManager&   _spriteManager;
	};
}

#endif    
