/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#ifndef LDL_Cpp98_hpp
#define LDL_Cpp98_hpp

#include <string>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GLLoad.h>

namespace LDL
{
	class Vec2i : public LDL_Vec2i
	{
	public:
		inline Vec2i()
		{
			x = 0;
			y = 0;
		}

		inline Vec2i(int px, int py)
		{
			x = px;
			y = py;
		}
	};

	class Color : public LDL_Color
	{
	public:
		inline Color()
		{
			r = 0;
			g = 0;
			b = 0;
			a = 26;
		}

		inline Color(uint8_t rv, uint8_t gv, uint8_t bv, uint8_t av = 255)
		{
			r = rv;
			g = gv;
			b = bv;
			a = av;
		}
	};

	class Event : public LDL_Event
	{
	public:
	};

	class Context
	{
	public:
		inline Context() :
			_context(NULL)
		{
			_context = LDL_ContextNew(LDL_ContextOpenGLLegacy);
		}

		inline ~Context()
		{
			LDL_ContextFree(_context);
		}

		inline size_t Get()
		{
			return LDL_ContextGet(_context);
		}

		inline LDL_Context* Impl()
		{
			return _context;
		}
	private:
		LDL_Context* _context;
	};

	class Result
	{
	public:
		inline Result() :
			_result(NULL)
		{
			_result = LDL_ResultNew();
		}

		inline ~Result()
		{
			LDL_ResultFree(_result);
		}

		inline bool IsOk()
		{
			return LDL_ResultIsOk(_result);
		}

		inline bool IsFail()
		{
			return LDL_ResultIsFail(_result);
		}

		const std::string& Message()
		{
			_message = LDL_ResultGetMessage(_result);

			return _message;
		}

		inline LDL_Result* Impl()
		{
			return _result;
		}
	private:
		LDL_Result* _result;
		std::string _message;
	};

	class Window
	{
	public:
		inline Window(Result& result, Context& context, const Vec2i& pos, const Vec2i& size, const std::string& title, size_t mode) :
			_window(NULL)
		{
			_window = LDL_WindowNew(result.Impl(), context.Impl(), pos, size, title.c_str(), mode);
		}

		inline ~Window()
		{
			LDL_WindowFree(_window);
		}

		inline LDL_Window* Impl()
		{
			return _window;
		}

		inline bool IsRunning()
		{
			return  LDL_WindowIsRunning(_window);
		}

		inline bool GetEvent(Event& event)
		{
			return LDL_WindowGetEvent(_window, &event);
		}

		inline void StopEvent()
		{
			LDL_WindowStopEvent(_window);
		}

		inline void Present()
		{
			LDL_WindowPresent(_window);
		}

		inline const Vec2i& GetSize()
		{
			LDL_Vec2i size = LDL_WindowGetSize(_window);

			_vec.x = size.x;
			_vec.y = size.y;

			return _vec;
		}
	private:
		Vec2i       _vec;
		LDL_Window* _window;
	};

	class Texture
	{
	public:
		inline Texture(Context& context, size_t pixelFormat, const Vec2i& size, uint8_t* pixels) :
			_texture(NULL)
		{
			_texture = LDL_TextureNewFromPixels(context.Impl(), pixelFormat, size, pixels);
		}

		inline Texture(Context& context, size_t pixelFormat, const Vec2i& size) :
			_texture(NULL)
		{
			_texture = LDL_TextureNewFromSize(context.Impl(), pixelFormat, size);
		}

		inline ~Texture()
		{
			LDL_TextureFree(_texture);
		}

		inline LDL_Texture* Impl()
		{
			return _texture;
		}

		inline const Vec2i& GetSize()
		{
			LDL_Vec2i size = LDL_TextureGetSize(_texture);

			_vec.x = size.x;
			_vec.y = size.y;

			return _vec;
		}
	private:
		Vec2i        _vec;
		LDL_Texture* _texture;
	};

	class Render
	{
	public:
		inline Render(Result& result, Context& context, Window& window) :
			_render(NULL)
		{
			_render = LDL_RenderNew(result.Impl(), context.Impl(), window.Impl());
		}

		inline ~Render()
		{
			LDL_RenderFree(_render);
		}

		inline LDL_Render* Impl()
		{
			return _render;
		}

		inline void Begin()
		{
			LDL_RenderBegin(_render);
		}

		inline void End()
		{
			LDL_RenderEnd(_render);
		}

		inline void SetColor(const Color& color)
		{
			LDL_Color clr = color;

			LDL_RenderSetColor(_render, clr);
		}

		inline void Clear()
		{
			LDL_RenderClear(_render);
		}

		inline void Line(const Vec2i& first, const Vec2i& last)
		{
			LDL_RenderLine2i(_render, first, last);
		}

		inline void Fill(const Vec2i& pos, const Vec2i& size)
		{
			LDL_RenderFill2i(_render, pos, size);
		}

		inline void Draw(Texture* texture, const Vec2i& dstPos, const Vec2i& dstSize, const Vec2i& srcPos, const Vec2i& srcSize)
		{
			LDL_RenderDraw(_render, texture->Impl(), (LDL_Vec2i*)&dstPos, (LDL_Vec2i*)&dstSize, (LDL_Vec2i*)&srcPos, (LDL_Vec2i*)&srcSize);
		}

		inline void Draw(Texture* texture, const Vec2i& dstPos)
		{
			Draw(texture, dstPos, texture->GetSize(), Vec2i(0, 0), texture->GetSize());
		}

		inline void Draw(Texture* texture, const Vec2i& dstPos, const Vec2i& dstSize)
		{
			Draw(texture, dstPos, dstSize, Vec2i(0, 0), texture->GetSize());
		}

		inline void Draw(Texture* texture, const Vec2i& dstPos, const Vec2i& dstSize, const Vec2i& srcPos)
		{
			Draw(texture, dstPos, dstSize, srcPos, texture->GetSize());
		}
	private:
		LDL_Render* _render;
	};

	class OpenGLLoader
	{
	public:
		inline OpenGLLoader(Result& result,size_t major, size_t minor) :
			_loader(NULL)
		{
			_loader = LDL_OpenGLLoaderNew(result.Impl(), major, minor);
		}

		inline ~OpenGLLoader()
		{
			LDL_OpenGLLoaderFree(_loader);
		}

		inline LDL_OpenGLLoader* Impl()
		{
			return _loader;
		}
	private:
		LDL_OpenGLLoader* _loader;
	};

	class BmpLoader
	{
	public:
		inline BmpLoader(Result& result) :
			_loader(NULL)
		{
			_loader = LDL_BmpLoaderNew(result.Impl());
		}

		inline ~BmpLoader()
		{
			LDL_BmpLoaderFree(_loader);
		}

		inline LDL_BmpLoader* Impl()
		{
			return _loader;
		}

		inline const Vec2i& GetSize()
		{
			LDL_Vec2i size = LDL_BmpLoaderGetSize(_loader);

			_vec.x = size.x;
			_vec.y = size.y;

			return _vec;
		}

		inline uint8_t* GetPixels()
		{
			return LDL_BmpLoaderGetPixels(_loader);
		}

		inline uint8_t GetPixelFormat()
		{
			return LDL_BmpLoaderGetPixelFormat(_loader);
		}

		inline uint8_t GetBytesPerPixels()
		{
			return LDL_BmpLoaderGetBytesPerPixels(_loader);
		}

		inline bool Load(const std::string& path)
		{
			return LDL_BmpLoaderLoadFromFile(_loader, path.c_str());
		}
	private:
		Vec2i          _vec;
		LDL_BmpLoader* _loader;
	};

	inline size_t Ticks()
	{
		return LDL_Ticks();
	}

	inline void Delay(size_t count)
	{
		return LDL_Delay(count);
	}
}

#endif
