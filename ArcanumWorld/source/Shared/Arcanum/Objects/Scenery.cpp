#include <Arcanum/Objects/Scenery.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;
using namespace Arcanum::Objects;
using namespace Arcanum::Graphics;

Scenery::Scenery() :
	_Body(nullptr)
{
}

void Scenery::Init(Sprite* sprite)
{
	_Body = sprite;
}

Sprite* Scenery::Body()
{
	return _Body;
}

const Vec2u& Scenery::Pos()
{
	return _MapObject.Pos();
}

void Scenery::Pos(const Vec2u& pos)
{
	_MapObject.Pos(pos);
}