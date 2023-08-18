#include <Arcanum/Objects/Critter.hpp>

using namespace LDL::Math;
using namespace Arcanum::Objects;

void Critter::Init(CritterScript* script)
{
	_Script = script;
}

const Vec2u& Critter::Pos()
{
	return _MapObject.Pos();
}

void Critter::Pos(const Vec2u& pos)
{
	_MapObject.Pos(pos);
}