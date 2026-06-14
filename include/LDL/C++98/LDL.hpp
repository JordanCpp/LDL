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
#include <stdarg.h>
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
		inline bool IsKeyPressed(uint8_t key)
		{
			return LDL_EventIsKeyPressed(this, key);
		}
	};

	class Result
	{
	public:
		inline Result() :
			_result(NULL)
		{
			_result = LDL_ResultCreate();
		}

		inline ~Result()
		{
			LDL_ResultDestroy(_result);
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

	class Surface
	{
	public:
		inline Surface(Result& result, uint8_t pixelFormat, Vec2i size) :
			_surface(NULL)
		{
			_surface = LDL_SurfaceCreateFromSize(result.Impl(), pixelFormat, size);
		}

		inline Surface(Result& result, uint8_t pixelFormat, Vec2i size, uint8_t* pixels) :
			_surface(NULL)
		{
			_surface = LDL_SurfaceCreateFromPixels(result.Impl(), pixelFormat, size, pixels);
		}

		inline ~Surface()
		{
			LDL_SurfaceDestroy(_surface);
		}

		inline LDL_Surface* Impl()
		{
			return _surface;
		}

		inline const Vec2i& GetCapacity()
		{
			LDL_Vec2i size = LDL_SurfaceGetCapacity(_surface);

			_vec.x = size.x;
			_vec.y = size.y;

			return _vec;
		}

		inline const Vec2i& GetSize()
		{
			LDL_Vec2i size = LDL_SurfaceGetSize(_surface);

			_vec.x = size.x;
			_vec.y = size.y;

			return _vec;
		}

		inline uint8_t GetBytesPerPixel()
		{
			return LDL_SurfaceGetBytesPerPixel(_surface);
		}

		inline uint8_t* GetPixels()
		{
			return LDL_SurfaceGetPixels(_surface);
		}

		inline uint8_t GetPixelFormat()
		{
			return LDL_SurfaceGetPixelFormat(_surface);
		}

		inline size_t GetPitch()
		{
			return LDL_SurfaceGetPitch(_surface);
		}

		inline const Color& GetColorKey()
		{
			LDL_Color color = LDL_SurfaceGetColorKey(_surface);

			_color.r = color.r;
			_color.g = color.g;
			_color.b = color.b;
			_color.a = color.a;

			return _color;
		}

		inline bool IsColorKey()
		{
			return LDL_SurfaceIsColorKey(_surface);
		}

		inline void SetColorKey(const Color& color)
		{
			LDL_SurfaceSetColorKey(_surface, LDL_ColorRgba(color.r, color.g, color.b, color.a));
		}
	private:
		Vec2i        _vec;
		Color        _color;
		LDL_Surface* _surface;
	};

	class Context
	{
	public:
		enum
		{
			Software = LDL_ContextSoftware,
			GLLegacy = LDL_ContextOpenGLLegacy,
			GLHybrid = LDL_ContextOpenGLHybrid,
			GLModern = LDL_ContextOpenGLModern
		};

		inline Context(Result& result, size_t mode = LDL_ContextOpenGLLegacy) :
			_context(NULL)
		{
			_context = LDL_ContextCreate(result.Impl(), mode);
		}

		inline ~Context()
		{
			LDL_ContextDestroy(_context);
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

	class Window
	{
	public:
		enum
		{
			FullScreen = LDL_WindowModeFullScreen,
			Resized    = LDL_WindowModeResized ,
			Fixed      = LDL_WindowModeFixed,
			Minimized  = LDL_WindowModeMinimized,
			Maximized  = LDL_WindowModeMaximized,
			Centered   = LDL_WindowModeCentered
		};

		inline Window(Result& result, Context& context, const Vec2i& pos, const Vec2i& size, const std::string& title, size_t mode) :
			_window(NULL)
		{
			_window = LDL_WindowCreate(result.Impl(), context.Impl(), pos, size, title.c_str(), mode);
		}

		inline ~Window()
		{
			LDL_WindowDestroy(_window);
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

		inline void SetTitle(const std::string& title)
		{
			LDL_WindowSetTitle(_window, title.c_str());
		}
	private:
		Vec2i       _vec;
		LDL_Window* _window;
	};

	class Texture
	{
	public:
		inline Texture(Result& result, Context& context, size_t pixelFormat, const Vec2i& size, uint8_t* pixels) :
			_texture(NULL)
		{
			_texture = LDL_TextureCreateFromPixels(result.Impl(), context.Impl(), pixelFormat, size, pixels);
		}

		inline Texture(Result& result, Context& context, size_t pixelFormat, const Vec2i& size) :
			_texture(NULL)
		{
			_texture = LDL_TextureCreateFromSize(result.Impl(), context.Impl(), pixelFormat, size);
		}

		inline Texture(Result& result, Context& context, Surface* surface) :
			_texture(NULL)
		{
			_texture = LDL_TextureCreateFromSurface(result.Impl(), context.Impl(), surface->Impl());
		}

		inline ~Texture()
		{
			LDL_TextureDestroy(_texture);
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

	class Render2D
	{
	public:
		inline Render2D(Result& result, Context& context, Window& window) :
			_render(NULL)
		{
			_render = LDL_2DRenderCreate(result.Impl(), context.Impl(), window.Impl());
		}

		inline ~Render2D()
		{
			LDL_2DRenderDestroy(_render);
		}

		inline LDL_2DRender* Impl()
		{
			return _render;
		}

		inline void Begin()
		{
			LDL_2DRenderBegin(_render);
		}

		inline void End()
		{
			LDL_2DRenderEnd(_render);
		}

		inline void SetColor(const Color& color)
		{
			LDL_Color clr = color;

			LDL_2DRenderSetColor(_render, clr);
		}

		inline void Clear()
		{
			LDL_2DRenderClear(_render);
		}

		inline void Line(const Vec2i& first, const Vec2i& last)
		{
			LDL_2DRenderLine(_render, first, last);
		}

		inline void Fill(const Vec2i& pos, const Vec2i& size)
		{
			LDL_2DRenderFill(_render, pos, size);
		}

		inline void Draw(Texture* texture, const Vec2i& dstPos, const Vec2i& dstSize, const Vec2i& srcPos, const Vec2i& srcSize)
		{
			LDL_2DRenderDraw(_render, texture->Impl(), (LDL_Vec2i*)&dstPos, (LDL_Vec2i*)&dstSize, (LDL_Vec2i*)&srcPos, (LDL_Vec2i*)&srcSize);
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

		inline size_t GetLayer()
		{
			return LDL_2DRenderGetLayer(_render);
		}

		inline void SetLayer(size_t layer)
		{
			LDL_2DRenderSetLayer(_render, layer);
		}
	private:
		LDL_2DRender* _render;
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
			_loader = LDL_BmpLoaderCreate(result.Impl());
		}

		inline ~BmpLoader()
		{
			LDL_BmpLoaderDestroy(_loader);
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
		LDL_Delay(count);
	}

	class Formatter
	{
	public:
		inline Formatter() :
			_formatter(NULL)
		{
		}

		inline ~Formatter()
		{
			LDL_FormatterDestroy(_formatter);
		}

		inline LDL_Formatter* Impl()
		{
			return _formatter;
		}

		inline const char* Format(const char* format, ...)
		{
			va_list args;
			const char* res;

			va_start(args, format);
			res = LDL_FormatterVFormat(_formatter, format, args);
			va_end(args);

			return res;
		}
	private:
		LDL_Formatter* _formatter;
	};

	class FpsCounter
	{
	public:
		inline FpsCounter(Result& result) :
			_fpsCounter(NULL)
		{
			_fpsCounter = LDL_FpsCounterCreate(result.Impl());
		}

		inline ~FpsCounter()
		{
			LDL_FpsCounterDestroy(_fpsCounter);
		}

		inline LDL_FpsCounter* Impl()
		{
			return _fpsCounter;
		}

		inline void Start()
		{
			LDL_FpsCounterStart(_fpsCounter);
		}

		inline bool Calc()
		{
			return LDL_FpsCounterCalc(_fpsCounter);
		}

		inline size_t Fps()
		{
			return LDL_FpsCounterFps(_fpsCounter);
		}
	private:
		LDL_FpsCounter* _fpsCounter;
	};

	class FpsLimiter
	{
	public:
		inline FpsLimiter(Result& result, size_t fps = LDL_FpsLimiterDefault) :
			_fpsLimiter(NULL)
		{
			_fpsLimiter = LDL_FpsLimiterCreate(result.Impl(), fps);
		}

		inline ~FpsLimiter()
		{
			LDL_FpsLimiterDestroy(_fpsLimiter);
		}

		inline LDL_FpsLimiter* Impl()
		{
			return _fpsLimiter;
		}

		inline void Mark()
		{
			LDL_FpsLimiterMark(_fpsLimiter);
		}

		inline void Throttle()
		{
			LDL_FpsLimiterThrottle(_fpsLimiter);
		}
	private:
		LDL_FpsLimiter* _fpsLimiter;
	};

	class VertexBuffer
	{
	public:
		inline VertexBuffer(Context& context, size_t fvf) :
			_buffer(NULL)
		{
			_buffer = LDL_VertexBufferNew(context.Impl(), fvf);
		}

		inline ~VertexBuffer()
		{
			LDL_VertexBufferFree(_buffer);
		}

		inline LDL_VertexBuffer* Impl()
		{
			return _buffer;
		}

		inline void Copy(size_t size, size_t count, void* source)
		{
			LDL_VertexBufferCopy(_buffer, size, count, source);
		}

	private:
		LDL_VertexBuffer* _buffer;
	};

	class Render3D
	{
	public:
		inline Render3D(Result& result, Context& context, Window& window) :
			_render(NULL)
		{
			_render = LDL_3DRenderCreate(result.Impl(), context.Impl(), window.Impl());
		}

		inline ~Render3D()
		{
			LDL_3DRenderDestroy(_render);
		}

		inline LDL_3DRender* Impl()
		{
			return _render;
		}

		inline void Begin()
		{
			LDL_3DRenderBegin(_render);
		}

		inline void End()
		{
			LDL_3DRenderEnd(_render);
		}

		inline void Clear(float r, float g, float b)
		{
			LDL_3DRenderClear(_render, r, g, b);
		}

		inline void Draw(VertexBuffer* buffer)
		{
			LDL_3DRenderDraw(_render, buffer->Impl());
		}

		inline void SetWorld(const float* matrix)
		{
			LDL_3DRenderSetWorld(_render, matrix);
		}

		inline void SetView(const float* matrix)
		{
			LDL_3DRenderSetView(_render, matrix);
		}

		inline void SetProjection(const float* matrix)
		{
			LDL_3DRenderSetProjection(_render, matrix);
		}

	private:
		LDL_3DRender* _render;
	};

	class ImageLoader
	{
	public:
		inline ImageLoader(Result& result) :
			_loader(NULL)
		{
			_loader = LDL_ImageLoaderCreate(result.Impl());
		}

		inline ~ImageLoader()
		{
			LDL_ImageLoaderDestroy(_loader);
		}

		inline LDL_ImageLoader* Impl()
		{
			return _loader;
		}

		inline void Clear()
		{
			LDL_ImageLoaderClear(_loader);
		}

		inline void LoadFromFile(const std::string& path)
		{
			return LDL_ImageLoaderLoadFromFile(_loader, path.c_str());
		}

		inline const Vec2i& GetSize()
		{
			LDL_Vec2i size = LDL_ImageLoaderGetSize(_loader);

			_size.x = size.x;
			_size.y = size.y;

			return _size;
		}

		inline uint8_t* GetPixels()
		{
			return LDL_ImageLoaderGetPixels(_loader);
		}

		inline uint8_t GetPixelFormat()
		{
			return LDL_ImageLoaderGetPixelFormat(_loader);
		}

	private:
		Vec2i            _size;
		LDL_ImageLoader* _loader;
	};

	class Font
	{
	public:
		inline Font(Result& result, const std::string& path, int size) :
			_font(NULL)
		{
			_font = LDL_FontLoad(result.Impl(), path.c_str(), size);
		}

		inline ~Font()
		{
			LDL_FontDestroy(_font);
		}

		inline LDL_Font* Impl()
		{
			return _font;
		}
	private:
		LDL_Font* _font;
	};

	class Rasterizer
	{
	public:
		inline Rasterizer(Result& result) :
			_rasterizer(NULL)
		{
			_rasterizer = LDL_RasterizerCreate(result.Impl());
		}

		inline ~Rasterizer()
		{
			LDL_RasterizerDestroy(_rasterizer);
		}

		inline LDL_Rasterizer* Impl()
		{
			return _rasterizer;
		}

		inline void Text(Font* font, Color color, const std::string& text)
		{
			LDL_RasterizerText(_rasterizer, font->Impl(), color, text.c_str());
		}

		inline const Vec2i& GetSize()
		{
			LDL_Vec2i size = LDL_RasterizerGetSize(_rasterizer);

			_size.x = size.x;
			_size.y = size.y;

			return _size;
		}

		inline uint8_t* GetPixels()
		{
			return LDL_RasterizerGetPixels(_rasterizer);
		}

		inline uint8_t GetPixelFormat()
		{
			return LDL_RasterizerGetPixelFormat(_rasterizer);
		}

	private:
		Vec2i           _size;
		LDL_Rasterizer* _rasterizer;
	};
}

#endif
