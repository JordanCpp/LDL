/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef LDL_Renders_SoftRndr_hpp
#define LDL_Renders_SoftRndr_hpp

#include <LDL/Window.hpp>
#include <LDL/BaseRndr.hpp>
#include <LDL/Surface.hpp>

class LDL_TextureSoftware
{
public:
	LDL_TextureSoftware(const LDL_Vec2i& size, uint8_t* pixels, uint8_t bytesPerPixel);
	LDL_TextureSoftware(const LDL_Vec2i& size, uint8_t bytesPerPixel);
	LDL_TextureSoftware(const LDL_Vec2i& size, uint8_t* pixels, LDL_Palette* palette);
	~LDL_TextureSoftware();
	void Copy(const LDL_Vec2i& dstPos, const LDL_Vec2i& srcSize, uint8_t* pixels, uint8_t bytesPerPixel);
	void Copy(const LDL_Vec2i& dstPos, LDL_Surface* surface, const LDL_Vec2i& srcSize);
	const LDL_Vec2i& Size();
	const LDL_Vec2i& Quad();
	LDL_Surface* GetSurface();
private:
	LDL_Vec2i   _Size;
	LDL_Vec2i   _Quad;
	LDL_Surface _Surface;
};

class LDL_RenderSoftware
{
public:
	LDL_RenderSoftware(LDL_WindowSoftware* window, LDL_Palette* palette = NULL);
	void Begin();
	void End();
	void Line(const LDL_Vec2i& pos1, const LDL_Vec2i& pos2);
	void Fill(const LDL_Vec2i& pos, const LDL_Vec2i& size);
	void SetColor(uint8_t index);
	void SetColor(const LDL_Color& color);
	void Clear();
	void Draw(LDL_TextureSoftware* image, const LDL_Vec2i& pos);
	void Draw(LDL_TextureSoftware* image, const LDL_Vec2i& pos, const LDL_Vec2i& size);
	void Draw(LDL_TextureSoftware* image, const LDL_Vec2i& dstPos, const LDL_Vec2i& srcPos, const LDL_Vec2i& srcSize);
	void Draw(LDL_TextureSoftware* image, const LDL_Vec2i& dstPos, const LDL_Vec2i& dstSize, const LDL_Vec2i& srcPos, const LDL_Vec2i& srcSize);
	void Draw(LDL_Surface* image, const LDL_Vec2i& pos);
	void Draw(LDL_Surface* image, const LDL_Vec2i& pos, const LDL_Vec2i& size);
	void Draw(LDL_Surface* image, const LDL_Vec2i& dstPos, const LDL_Vec2i& srcPos, const LDL_Vec2i& srcSize);
	void Draw(LDL_Surface* image, const LDL_Vec2i& dstPos, const LDL_Vec2i& dstSize, const LDL_Vec2i& srcPos, const LDL_Vec2i& srcSize);
private:
	LDL_WindowSoftware* _Window;
	LDL_BaseRender      _BaseRender;
	LDL_Surface*        _Screen;
};

#endif