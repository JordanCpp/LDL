// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Managers/ObjectManager.hpp>

using namespace Arcanum::Allocators;
using namespace Arcanum::Managers;
using namespace Arcanum::Objects;

ObjectManager::ObjectManager(ObjectAllocator* objectAllocator, SpriteManager* spriteManager) :
	_objectAllocator(objectAllocator),
	_spriteManager(spriteManager)
{
}

Scenery* ObjectManager::NewScenery(const std::string& name)
{
	Scenery* result = _objectAllocator->NewScenery();

	result->Init(_spriteManager->GetScenery(name));

	return result;
}

void ObjectManager::NewTile(Tile& object, const std::string& name)
{
	object.Init(_spriteManager->GetTile(name));
}