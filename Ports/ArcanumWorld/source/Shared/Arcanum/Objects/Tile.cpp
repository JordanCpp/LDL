#include <Arcanum/Objects/Tile.hpp>

using namespace LDL;
using namespace Arcanum::Objects;
using namespace Arcanum::Graphics;

Tile::Tile() :
	_Body(nullptr)
{
}

const Vec2u& Tile::Pos()
{
	return _MapObject.Pos();
}

void Tile::Pos(const Vec2u& pos)
{
	_MapObject.Pos(pos);
}

void Tile::Init(Sprite* sprite)
{
	_Body = sprite;
}

Sprite* Tile::Body()
{
	return _Body;
}