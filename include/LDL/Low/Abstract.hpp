#ifndef LDL_Low_Abstract_hpp
#define LDL_Low_Abstract_hpp

#include <LDL/Low/Color.hpp>
#include <LDL/Low/Point2u.hpp>
#include <LDL/Low/Event.hpp>
#include <LDL/Low/Config.hpp>

class LDL_ITexture
{
public:
private:
};

class LDL_IWindow
{
public:
	virtual ~LDL_IWindow() {};
	virtual bool Running() = 0;
	virtual void PollEvents() = 0;
	virtual bool GetEvent(LDL_Event& event) = 0;
	virtual bool WaitEvent(LDL_Event& event) = 0;
	virtual void StopEvent() = 0;
	virtual void Title(const char* title) = 0;
	virtual const char* Title() = 0;
	virtual const LDL_Point2u& Size() = 0;
	virtual const LDL_Point2u& Pos() = 0;
private:
};

class LDL_ISurface
{
public:
	virtual ~LDL_ISurface() {};
	virtual uint8_t LDL_FAR* Pixels() = 0;
	virtual const LDL_Point2u& Size() = 0;
	virtual uint8_t Bpp() = 0;
	//virtual size_t Capacity() = 0;
	//virtual void Resize(const LDL_Point2u& size, uint8_t bpp) = 0;
private:
};

class LDL_IRender
{
public:
	virtual ~LDL_IRender() {};
	virtual void SetColor(const LDL_Color& color) = 0;
	virtual void Line(const LDL_Point2u& first, const LDL_Point2u& last) = 0;
	virtual void Fill(const LDL_Point2u& pos, const LDL_Point2u& size) = 0;
	virtual void Clear() = 0;
	virtual void Begin() = 0;
	virtual void End() = 0;
	virtual void Draw(LDL_ISurface* surface, const LDL_Point2u& pos) = 0;
private:
};

class LDL_IRenderContext
{
public:
	virtual ~LDL_IRenderContext() {};
	virtual size_t Mode() = 0;
private:
};

class LDL_ILibrary
{
public:
	virtual ~LDL_ILibrary() {};
	virtual LDL_VoidFuncPtr Function(const char* name) = 0;
private:
};

#endif
