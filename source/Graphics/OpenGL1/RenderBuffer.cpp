#include "RenderBuffer.hpp"
#include "Util.hpp"

using namespace LDL::Graphics;

RenderBuffer::RenderBuffer()
{
	_Elements.reserve(1024 * 8);
}

void RenderBuffer::Reset()
{
	_Elements.clear();
}

void RenderBuffer::Texture(const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize, size_t textureId, size_t textureQuad)
{
	RenderElement element;

	element.type                       = RenderElement::IsTexture;
	element.textureElement.dstPosX     = (uint16_t)dstPos.PosX();
	element.textureElement.dstPosY     = (uint16_t)dstPos.PosY();
	element.textureElement.dstSizeX    = (uint16_t)dstSize.PosX();
	element.textureElement.dstSizeY    = (uint16_t)dstSize.PosY();
	element.textureElement.srcPosX     = (uint16_t)srcPos.PosX();
	element.textureElement.srcPosY     = (uint16_t)srcPos.PosY();
	element.textureElement.srcSizeX    = (uint16_t)srcSize.PosX();
	element.textureElement.srcSizeY    = (uint16_t)srcSize.PosY();
	element.textureElement.textureId   = (uint16_t)textureId;
	element.textureElement.textureQuad = (uint16_t)textureQuad;

	_Elements.push_back(element);
}

void RenderBuffer::Line(const Point2u& first, const Point2u& last, const Color& color)
{
	RenderElement element;

	element.type               = RenderElement::IsLine;
	element.lineElement.r      = color.Red();
	element.lineElement.g      = color.Green();
	element.lineElement.b      = color.Blue();
	element.lineElement.firstX = (uint16_t)first.PosX();
	element.lineElement.firstY = (uint16_t)first.PosY();
	element.lineElement.lastX  = (uint16_t)last.PosX();
	element.lineElement.lastY  = (uint16_t)last.PosY();

	_Elements.push_back(element);
}

void RenderBuffer::Fill(const Point2u& pos, const Point2u& size, const Color& color)
{
	RenderElement element;

	element.type              = RenderElement::IsFill;
	element.fillElement.r     = color.Red();
	element.fillElement.g     = color.Green();
	element.fillElement.b     = color.Blue();
	element.fillElement.posX  = (uint16_t)pos.PosX();
	element.fillElement.posY  = (uint16_t)pos.PosY();
	element.fillElement.sizeX = (uint16_t)size.PosX();
	element.fillElement.sizeY = (uint16_t)size.PosY();

	_Elements.push_back(element);
}

void RenderBuffer::Clear(const Color& color)
{
	RenderElement element;

	element.type           = RenderElement::IsClear;
	element.clearElement.r = color.Red();
	element.clearElement.g = color.Green();
	element.clearElement.b = color.Blue();

	_Elements.push_back(element);
}

void RenderBuffer::Draw()
{
	for (size_t i = 0; i < _Elements.size(); i++)
	{
		if (_Elements[i].type == RenderElement::IsTexture)
			Draw(_Elements[i].textureElement);
		else if (_Elements[i].type == RenderElement::IsLine)
			Draw(_Elements[i].lineElement);
		else if (_Elements[i].type == RenderElement::IsFill)
			Draw(_Elements[i].fillElement);
		else if (_Elements[i].type == RenderElement::IsClear)
			Draw(_Elements[i].clearElement);
	}
}

void RenderBuffer::Draw(TextureElement& src)
{
	GL_CHECK(glEnable(GL_TEXTURE_2D));

	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)src.textureId));

	Util::DrawQuad(Point2u(src.dstPosX, src.dstPosY), Point2u(src.dstSizeX, src.dstSizeY), Point2u(src.srcPosX, src.srcPosY), Point2u(src.srcSizeX, src.srcSizeY), src.textureQuad);

	GL_CHECK(glDisable(GL_TEXTURE_2D));
}

void RenderBuffer::Draw(LineElement& src)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(Color(src.r, src.g, src.b), r, g, b);

	glBegin(GL_LINES);
	glColor3f(r, g, b);
	glVertex2i(src.firstX, src.firstY);
	glVertex2i(src.lastX, src.lastY);
	glEnd();
}

void RenderBuffer::Draw(FillElement& src)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(Color(src.r, src.g, src.b), r, g, b);

	GLint x = (GLint)src.posX;
	GLint y = (GLint)src.posY;
	GLint w = (GLint)src.sizeX;
	GLint h = (GLint)src.sizeY;

	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex2i(x, y + h);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glEnd();
}

void RenderBuffer::Draw(ClearElement& src)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(Color(src.r, src.g, src.b), r, g, b);

	GL_CHECK(glClearColor(r, g, b, 1.0f));
	GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}