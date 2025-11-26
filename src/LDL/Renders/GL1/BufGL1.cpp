// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Renders/GL/Util.hpp>
#include <LDL/Renders/GL1/BufGL1.hpp>

LDL_RenderBuffer::LDL_RenderBuffer()
{
	_elements.reserve(1024 * 8);
}

void LDL_RenderBuffer::Reset()
{
	_elements.clear();
}

void LDL_RenderBuffer::Texture(const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize, size_t textureId, size_t textureQuad)
{
	LDL_RenderElement element;

	element.type                       = LDL_RenderElement::IsTexture;
	element.textureElement.dstPosX     = (uint16_t)dstPos.x;
	element.textureElement.dstPosY     = (uint16_t)dstPos.y;
	element.textureElement.dstSizeX    = (uint16_t)dstSize.x;
	element.textureElement.dstSizeY    = (uint16_t)dstSize.y;
	element.textureElement.srcPosX     = (uint16_t)srcPos.x;
	element.textureElement.srcPosY     = (uint16_t)srcPos.y;
	element.textureElement.srcSizeX    = (uint16_t)srcSize.x;
	element.textureElement.srcSizeY    = (uint16_t)srcSize.y;
	element.textureElement.textureId   = (uint16_t)textureId;
	element.textureElement.textureQuad = (uint16_t)textureQuad;

	_elements.push_back(element);
}

void LDL_RenderBuffer::Line(const LDL_Vec2u& first, const LDL_Vec2u& last, const LDL_Color& color)
{
	LDL_RenderElement element;

	element.type               = LDL_RenderElement::IsLine;
	element.lineElement.r      = color.r;
	element.lineElement.g      = color.g;
	element.lineElement.b      = color.b;
	element.lineElement.firstX = (uint16_t)first.x;
	element.lineElement.firstY = (uint16_t)first.y;
	element.lineElement.lastX  = (uint16_t)last.x;
	element.lineElement.lastY  = (uint16_t)last.y;

	_elements.push_back(element);
}

void LDL_RenderBuffer::Fill(const LDL_Vec2u& pos, const LDL_Vec2u& size, const LDL_Color& color)
{
	LDL_RenderElement element;

	element.type              = LDL_RenderElement::IsFill;
	element.fillElement.r     = color.r;
	element.fillElement.g     = color.g;
	element.fillElement.b     = color.b;
	element.fillElement.posX  = (uint16_t)pos.x;
	element.fillElement.posY  = (uint16_t)pos.y;
	element.fillElement.sizeX = (uint16_t)size.x;
	element.fillElement.sizeY = (uint16_t)size.y;

	_elements.push_back(element);
}

void LDL_RenderBuffer::TextureBatcher(size_t textureId, size_t count, Quad* quads)
{
	LDL_RenderElement element;

	element.type                          = LDL_RenderElement::IsTextureBatcher;
	element.textureBatcherElement.texture = textureId;
	element.textureBatcherElement.count   = count;
	element.textureBatcherElement.quads   = quads;

	_elements.push_back(element);
}

void LDL_RenderBuffer::Clear(const LDL_Color& color)
{
	LDL_RenderElement element;

	element.type           = LDL_RenderElement::IsClear;
	element.clearElement.r = color.r;
	element.clearElement.g = color.g;
	element.clearElement.b = color.b;

	_elements.push_back(element);
}

void LDL_RenderBuffer::Draw()
{
	for (size_t i = 0; i < _elements.size(); i++)
	{
		if (_elements[i].type == LDL_RenderElement::IsTexture)
			Draw(_elements[i].textureElement);
		else if (_elements[i].type == LDL_RenderElement::IsLine)
			Draw(_elements[i].lineElement);
		else if (_elements[i].type == LDL_RenderElement::IsFill)
			Draw(_elements[i].fillElement);
		else if (_elements[i].type == LDL_RenderElement::IsClear)
			Draw(_elements[i].clearElement);
		else if (_elements[i].type == LDL_RenderElement::IsTextureBatcher)
			Draw(_elements[i].textureBatcherElement);
	}
}

void LDL_RenderBuffer::Draw(LDL_TextureElement& src)
{
	GL_CHECK(glEnable(GL_TEXTURE_2D));
	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)src.textureId));

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	Quad quad;

	CalcQuad(quad, src.dstPosX, src.dstPosY, src.dstSizeX, src.dstSizeY, src.srcPosX, src.srcPosY, src.srcSizeX, src.srcSizeY, src.textureQuad);

	glVertexPointer(3, GL_FLOAT, sizeof(float) * 5, &quad.data[0]);
	glTexCoordPointer(2, GL_FLOAT, sizeof(float) * 5, &quad.data[3]);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	GL_CHECK(glDisable(GL_TEXTURE_2D));
}

void LDL_RenderBuffer::Draw(LDL_LineElement& src)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Normalize(LDL_Color(src.r, src.g, src.b), r, g, b);

	glBegin(GL_LINES);
	glColor3f(r, g, b);
	glVertex2i(src.firstX, src.firstY);
	glVertex2i(src.lastX, src.lastY);
	glEnd();
}

void LDL_RenderBuffer::Draw(LDL_FillElement& src)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Normalize(LDL_Color(src.r, src.g, src.b), r, g, b);

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

void LDL_RenderBuffer::Draw(LDL_ClearElement& src)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Normalize(LDL_Color(src.r, src.g, src.b), r, g, b);

	GL_CHECK(glClearColor(r, g, b, 1.0f));
	GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void LDL_RenderBuffer::Draw(LDL_TextureBatcherElement& src)
{
	GL_CHECK(glEnable(GL_TEXTURE_2D));
	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)src.texture));

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(float) * 5, &src.quads->data[0]);
	glTexCoordPointer(2, GL_FLOAT, sizeof(float) * 5, &src.quads->data[3]);

	glDrawArrays(GL_TRIANGLES, 0, (GLsizei)src.count * 6);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	GL_CHECK(glDisable(GL_TEXTURE_2D));
}
