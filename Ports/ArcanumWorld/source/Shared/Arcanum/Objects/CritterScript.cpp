#include <Arcanum/Objects/CritterScript.hpp>
#include <stdio.h>

using namespace Arcanum::Objects;

Critter* CritterScript::Self()
{
	return _Critter;
}

void CritterScript::Init(Critter* critter)
{
	_Critter = critter;
}