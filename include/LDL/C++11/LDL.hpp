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

#ifndef LDL_Cpp11_hpp
#define LDL_Cpp11_hpp

#include <string>
#include <memory>
#include <utility>
#include <functional>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GLLoad.h>

namespace LDL
{
    struct Vec2i : public LDL_Vec2i
    {
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

    struct Color : public LDL_Color
    {
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

    template<typename T, void (*Deleter)(T*)>
    using UniquePtr = std::unique_ptr<T, std::function<void(T*)>>;

    class Context
    {
    public:
        inline Context() :
            _context(LDL_ContextNew(LDL_ContextOpenGLLegacy), LDL_ContextFree)
        {
            if (!_context) 
            { 
            }
        }

        inline size_t Get() const
        { 
            return LDL_ContextGet(_context.get()); 
        }

        inline LDL_Context* Impl() const
        { 
            return _context.get(); 
        }
    private:
        std::unique_ptr<LDL_Context, decltype(&LDL_ContextFree)> _context;
    };

    class Result
    {
    public:
        inline Result() : 
            _result(LDL_ResultNew(), LDL_ResultFree) 
        {
        }

        inline bool IsOk() const
        { 
            return LDL_ResultIsOk(_result.get());
        }

        inline bool IsFail() const
        { 
            return LDL_ResultIsFail(_result.get()); 
        }

        inline const std::string& Message()
        {
            _message = LDL_ResultGetMessage(_result.get());
            return _message;
        }

        inline LDL_Result* Impl() const 
        { 
            return _result.get();
        }

    private:
        std::unique_ptr<LDL_Result, decltype(&LDL_ResultFree)> _result;
        std::string _message;
    };

    class Window
    {
    public:
        inline Window(Result& result, Context& context, const Vec2i& pos, const Vec2i& size, const std::string& title, size_t mode) :
            _window(LDL_WindowNew(result.Impl(), context.Impl(), pos, size, title.c_str(), mode), LDL_WindowFree)
        {
        }

        inline LDL_Window* Impl() const 
        { 
            return _window.get(); 
        }

        inline bool IsRunning() const 
        { 
            return LDL_WindowIsRunning(_window.get());
        }

        inline bool GetEvent(Event& event) 
        { 
            return LDL_WindowGetEvent(_window.get(), &event); 
        }
        
        inline void StopEvent()
        { 
            LDL_WindowStopEvent(_window.get()); 
        }

        inline void Present() 
        {
            LDL_WindowPresent(_window.get());
        }

        inline Vec2i GetSize() const
        {
            LDL_Vec2i size = LDL_WindowGetSize(_window.get());
            return Vec2i(size.x, size.y);
        }

    private:
        std::unique_ptr<LDL_Window, decltype(&LDL_WindowFree)> _window;
    };

    class Texture
    {
    public:
        inline Texture(Context& context, size_t pixelFormat, const Vec2i& size, uint8_t* pixels)
            : _texture(LDL_TextureNewFromPixels(context.Impl(), pixelFormat, size, pixels), LDL_TextureFree)
        {
        }

        inline Texture(Context& context, size_t pixelFormat, const Vec2i& size)
            : _texture(LDL_TextureNewFromSize(context.Impl(), pixelFormat, size), LDL_TextureFree)
        {
        }

        inline LDL_Texture* Impl() const 
        {
            return _texture.get(); 
        }

        inline Vec2i GetSize() const
        {
            LDL_Vec2i size = LDL_TextureGetSize(_texture.get());
            return Vec2i(size.x, size.y);
        }

    private:
        std::unique_ptr<LDL_Texture, decltype(&LDL_TextureFree)> _texture;
    };

    class Render
    {
    public:
        inline Render(Result& result, Context& context, Window& window)
            : _render(LDL_RenderNew(result.Impl(), context.Impl(), window.Impl()), LDL_RenderFree)
        {
        }

        inline LDL_Render* Impl() const
        {
            return _render.get(); 
        }

        inline void Begin()
        { 
            LDL_RenderBegin(_render.get());
        }

        inline void End()
        { 
            LDL_RenderEnd(_render.get());
        }

        inline void SetColor(const Color& color)
        { 
            LDL_RenderSetColor(_render.get(), color); 
        }

        inline void Clear()
        { 
            LDL_RenderClear(_render.get());
        }

        inline void Line(const Vec2i& first, const const Vec2i& last)
        { 
            LDL_RenderLine2i(_render.get(), first, last); 
        }

        inline void Fill(const Vec2i& pos, const Vec2i& size)
        { 
            LDL_RenderFill2i(_render.get(), pos, size); 
        }

        inline void Draw(Texture* texture, const Vec2i& dstPos, const Vec2i& dstSize, const Vec2i& srcPos, const Vec2i& srcSize)
        {
            LDL_RenderDraw(_render.get(), texture->Impl(), (LDL_Vec2i*)(&dstPos), (LDL_Vec2i*)(&dstSize), (LDL_Vec2i*)(&srcPos), (LDL_Vec2i*)(&srcSize));
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
        std::unique_ptr<LDL_Render, decltype(&LDL_RenderFree)> _render;
    };

    class BmpLoader
    {
    public:
        inline BmpLoader(Result& result) :
            _loader(LDL_BmpLoaderNew(result.Impl()), LDL_BmpLoaderFree) 
        {
        }

        inline Vec2i GetSize() const
        {
            LDL_Vec2i size = LDL_BmpLoaderGetSize(_loader.get());
            return Vec2i(size.x, size.y);
        }

        inline uint8_t* GetPixels() const
        { 
            return LDL_BmpLoaderGetPixels(_loader.get()); 
        }

        inline uint8_t GetPixelFormat() const
        {
            return LDL_BmpLoaderGetPixelFormat(_loader.get());
        }

        inline uint8_t GetBytesPerPixels() const
        { 
            return LDL_BmpLoaderGetBytesPerPixels(_loader.get());
        }

        inline bool Load(const std::string& path)
        { 
            return LDL_BmpLoaderLoadFromFile(_loader.get(), path.c_str()); 
        }
    private:
        std::unique_ptr<LDL_BmpLoader, decltype(&LDL_BmpLoaderFree)> _loader;
    };

    inline size_t Ticks()
    {
        return LDL_Ticks(); 
    }

    inline void Delay(size_t count) 
    { 
        LDL_Delay(count); 
    }
}

#endif
