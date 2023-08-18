#include <Arcanum/Painters/LocationPainter.hpp>

using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace Arcanum::Painters;
using namespace Arcanum::Objects;
using namespace Arcanum::Graphics;

LocationPainter::LocationPainter(Render* render, LocationData* location) :
	_Render(render),
	_Location(location)
{
}

void LocationPainter::DrawTiles(const Vec2u& start)
{
	Vec2u pos;

	for (size_t i = 0; i < _Location->TileObjects().size(); i++)
	{
		pos = _Location->TileObjects()[i].Pos();

		Texture* texture = _Location->TileObjects()[i].Body()->Single()->GetTexture();

		_Render->Draw(texture, Vec2u(start.x + pos.x, start.y + pos.y));
	}
}

void LocationPainter::DrawSceneries(const Vec2u& start)
{
	for (size_t i = 0; i < _Location->SceneryObjects().size(); i++)
	{
		Scenery* object = _Location->SceneryObjects()[i];
		size_t   index  = _Location->Index(object->Pos());
		Vec2u    tile   = _Location->TileObjects()[index].Pos();

		Sprite* sprite = object->Body();

		if (sprite != nullptr)
		{
			size_t x = sprite->Single()->Offset().x;
			size_t y = sprite->Single()->Offset().y;

			Vec2u center = Vec2u(tile.x + Tile::Width / 2, tile.y + Tile::Height / 2);

			_Render->Draw(sprite->Single()->GetTexture(), Vec2u(start.x + center.x - x, start.y + center.y - y));
		}
	}
}

void LocationPainter::Draw(const Vec2u& start)
{
	DrawTiles(start);
	DrawSceneries(start);
}