#include <Arcanum/Painters/LocationPainter.hpp>

using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace Arcanum::Painters;
using namespace Arcanum::Objects;
using namespace Arcanum::Graphics;

LocationPainter::LocationPainter(Render* render, LocationData* location) :
	_render(render),
	_location(location)
{
}

void LocationPainter::DrawTiles(const Vec2u& start)
{
	Vec2u pos;

	for (size_t i = 0; i < _location->TileObjects().size(); i++)
	{
		pos = _location->TileObjects()[i].Pos();

		Texture* texture = _location->TileObjects()[i].Body()->Single()->GetTexture();

		_render->Draw(texture, Vec2u(start.x + pos.x, start.y + pos.y));
	}
}

void LocationPainter::DrawSceneries(const Vec2u& start)
{
	for (size_t i = 0; i < _location->SceneryObjects().size(); i++)
	{
		Scenery* object = _location->SceneryObjects()[i];
		size_t   index  = _location->Index(object->Pos());
		Vec2u    tile   = _location->TileObjects()[index].Pos();

		Sprite* sprite = object->Body();

		if (sprite != nullptr)
		{
			size_t x = sprite->Single()->Offset().x;
			size_t y = sprite->Single()->Offset().y;

			Vec2u center = Vec2u(tile.x + Tile::Width / 2, tile.y + Tile::Height / 2);

			_render->Draw(sprite->Single()->GetTexture(), Vec2u(start.x + center.x - x, start.y + center.y - y));
		}
	}
}

void LocationPainter::Draw(const Vec2u& start)
{
	DrawTiles(start);
	DrawSceneries(start);
}