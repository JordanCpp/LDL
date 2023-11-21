#include <Arcanum/Objects/MapObject.hpp>

using namespace LDL::Math;
using namespace Arcanum::Objects;

const Vec2u& MapObject::Pos()
{
	return _Pos;
}

void MapObject::Pos(const Vec2u& pos)
{
	_Pos = pos;
}