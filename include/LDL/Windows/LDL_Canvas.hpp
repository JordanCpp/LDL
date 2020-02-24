#ifndef _LDL_Canvas_hpp_
#define _LDL_Canvas_hpp_

#include <queue>
#include <fstream>
#include <string>
#include <stdint.h> 
#include <windows.h>

namespace LDL
{

class Canvas
{
public:
  void Caption(const std::string & Source);
  Canvas(Rect Rt);
  ~Canvas();
  uint16_t Width();
  uint16_t Height();
  void Present();
  void SetColor(Color Cr);
  void Clear();
  void DrawPixel(uint16_t x, uint16_t y);
  void DrawRect(Rect Rt);
  void StopEvent();
  bool GetEvent(Event & Dest);
  bool WaitEvent(Event & Dest);
  void DrawText(uint16_t x, uint16_t y, const std::string & Source);
  void DrawXLine(uint16_t x, uint16_t y, uint16_t c);
  void DrawYLine(uint16_t x, uint16_t y, uint16_t c);
//private:
  void Process();
  static LRESULT CALLBACK WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam);
  LRESULT CALLBACK Handler(UINT Message, WPARAM WParam, LPARAM LParam);
  Rect        mRect;
  Color       mColor;
  WNDCLASSEXW mWcx;
  HINSTANCE   mHinst;
  HWND        mHwnd;
  MSG         mMsg;
  HDC         mHdc;
  BITMAPINFO  ih;
  size_t      mFps;
  std::queue<Event> mEvents;
  bool mRunning;
  std::vector<Color> mBuffer;
};

void Canvas::Caption(const std::string & Source)
{
  SetWindowText(mHwnd, Source.c_str());
}

Canvas::Canvas(Rect Rt):
mRect(Rt),
mColor(0, 0, 0)
{
  ZeroMemory(&mWcx, sizeof(mWcx));
  //mWcx     = {0};
  //mHinst   = {0};
  //mHwnd    = {0};
  //mMsg     = {0};
  mRunning = true;

  mWcx.cbSize        = sizeof(WNDCLASSEX);
  mWcx.style         = CS_HREDRAW | CS_VREDRAW;
  mWcx.lpfnWndProc   = WndProc;
  mWcx.hInstance     = mHinst;
  mWcx.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
  mWcx.lpszClassName = L"Hello";

  RegisterClassExW(&mWcx);

  mHwnd = CreateWindowW(L"Hello", L"Hello", WS_OVERLAPPEDWINDOW, mRect.PosX(), mRect.PosY(), mRect.Width(), mRect.Height(), 0, 0, mHinst, 0);

  #ifdef LDL_32bit
    SetWindowLong(mHwnd, GWL_WNDPROC, (LONG)WndProc);
    SetWindowLong(mHwnd, GWL_USERDATA, (LONG)this);
  #elif LDL_64bit
    SetWindowLongPtr(mHwnd, GWLP_WNDPROC, (LONG_PTR)WndProc);
    SetWindowLongPtr(mHwnd, GWLP_USERDATA, (LONG_PTR)this);
  #endif

  mHdc = GetDC(mHwnd);

  mBuffer.resize(mRect.Width() * mRect.Height(), Color(0, 0, 0));
  
  ShowWindow(mHwnd, SW_SHOW);  
}

Canvas::~Canvas()
{
  ReleaseDC(mHwnd, mHdc);
  PostQuitMessage(0);
}

uint16_t Canvas::Width()
{
  return mRect.Width();
}

uint16_t Canvas::Height()
{
  return mRect.Height();
}

void Canvas::Present()
{ 
  ZeroMemory(&ih, sizeof(ih));

  ih.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
  ih.bmiHeader.biWidth       = mRect.Width();
  ih.bmiHeader.biHeight      = -(int32_t)mRect.Height();
  ih.bmiHeader.biPlanes      = 1;
  ih.bmiHeader.biBitCount    = 32;
  ih.bmiHeader.biCompression = BI_RGB;

  SetDIBitsToDevice(mHdc, mRect.PosX(), mRect.PosY(), mRect.Width(), mRect.Height(), 0, 0, 0, mRect.Height(), &mBuffer[0], &ih, DIB_RGB_COLORS);
}

void Canvas::SetColor(Color Cr)
{
  mColor = Cr;
}

void Canvas::Clear()
{
  mBuffer.clear();

  for (size_t i = 0; i < mBuffer.capacity(); i++)
  {
    mBuffer.push_back(mColor);
  }
}

void Canvas::DrawPixel(uint16_t x, uint16_t y)
{
  size_t i = (mRect.Width() * y) + x;

  mBuffer[i] = mColor;
}

void Canvas::DrawRect(Rect Rt)
{
  uint16_t x = Rt.PosX();
  uint16_t y = Rt.PosY();

  for (uint16_t i = 0; i < Rt.Width(); i++)
  {
    for (uint16_t j = 0; j < Rt.Height(); j++)
    {
      DrawPixel(x + i, y + j);
    }
  }
}

void Canvas::Process()
{
  while (PeekMessage(&mMsg, mHwnd, 0, 0, PM_REMOVE))
  {
    TranslateMessage(&mMsg);
    DispatchMessage(&mMsg);
  }
}

void Canvas::StopEvent()
{
  mRunning = false;
}

bool Canvas::WaitEvent(Event & Dest)
{
  if (mRunning == true)
  {
    bool Wait = false;

    while (Wait != true)
    {
      if (PeekMessage(&mMsg, mHwnd, 0, 0, PM_REMOVE))
      {
        Wait = true;
        TranslateMessage(&mMsg);
        DispatchMessage(&mMsg);
      }
      else
      {
        LDL::Delay(1);
      }
    }

    if (mEvents.empty() != true)
    {
      Dest = mEvents.front();
      mEvents.pop();
    }

    return true;

  }
  else
  {
    return false;
  }
}

bool Canvas::GetEvent(Event & Dest)
{
  if (mRunning == true)
  {
    //size_t Start = GetTickCount();
  
    Process();


    //if (1000 / mFps > GetTickCount() - Start)
    //{
    //  Sleep(1000 / mFps - (GetTickCount() - Start));
    //}
    
    if (mEvents.empty() != true)
    {
      Dest = mEvents.front();
      mEvents.pop();
    }



    return true;
  }
  else
  {
    return false;
  }
}

LRESULT CALLBACK Canvas::WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam)
{
  LRESULT Result;

  #ifdef LDL_32bit
    Canvas * This = (Canvas*)GetWindowLong(Hwnd, GWL_USERDATA);
  #elif LDL_64bit
    Canvas * This = (Canvas*)GetWindowLongPtr(Hwnd, GWLP_USERDATA);
  #endif

  if (This != NULL)
  {
    Result = This->Handler(Message, WParam, LParam);
  }
  else
  {
    Result = DefWindowProc(Hwnd, Message, WParam, LParam);
  }

  return Result;
}

LRESULT CALLBACK Canvas::Handler(UINT Message, WPARAM WParam, LPARAM LParam)
{
  Event Report = {0};

  switch (Message)
  {
    case WM_PAINT:
    break;  

    case WM_DESTROY:
      Report.Type = Event::IsQuit;
    break;  

    case WM_MOUSEMOVE:
      Report.Type = Event::IsMouseMove;
      Report.MouseMove.PosX = LOWORD(LParam);
      Report.MouseMove.PosY = HIWORD(LParam);
      mEvents.push(Report);
    break;  

    case WM_LBUTTONDOWN:
      Report.Type = Event::IsMouseButton;
      Report.MouseButton.Button = Event::ButtonLeft;
      Report.MouseButton.State  = Event::ButtonDown;
      Report.MouseButton.PosX   = LOWORD(LParam);
      Report.MouseButton.PosY   = HIWORD(LParam);
      mEvents.push(Report);
    break;

    case WM_LBUTTONUP:
      Report.Type = Event::IsMouseButton;
      Report.MouseButton.Button = Event::ButtonLeft;
      Report.MouseButton.State  = Event::ButtonUp;
      Report.MouseButton.PosX   = LOWORD(LParam);
      Report.MouseButton.PosY   = HIWORD(LParam);
      mEvents.push(Report);
    break;

    case WM_RBUTTONDOWN:
      Report.Type = Event::IsMouseButton;
      Report.MouseButton.Button = Event::ButtonRight;
      Report.MouseButton.State  = Event::ButtonDown;
      Report.MouseButton.PosX   = LOWORD(LParam);
      Report.MouseButton.PosY   = HIWORD(LParam);
      mEvents.push(Report);
    break;

    case WM_RBUTTONUP:
      Report.Type = Event::IsMouseButton;
      Report.MouseButton.Button = Event::ButtonRight;
      Report.MouseButton.State  = Event::ButtonUp;
      Report.MouseButton.PosX   = LOWORD(LParam);
      Report.MouseButton.PosY   = HIWORD(LParam);
      mEvents.push(Report);
    break;

    case WM_SIZE:
      Report.Type = Event::IsResize;
      
      Report.Resize.Width  = LOWORD(LParam);
      Report.Resize.Height = HIWORD(LParam);

      mRect.Size(Report.Resize.Width, Report.Resize.Height);
      
      mBuffer.resize(mRect.Width() * mRect.Height(), Color(0, 0, 0));

      mEvents.push(Report);
    break;  

  }

  return DefWindowProc(mHwnd, Message, WParam, LParam);
}

void Canvas::DrawText(uint16_t x, uint16_t y, const std::string & Source)
{
  TextOut(mHdc, x, y, Source.c_str(), (uint16_t)Source.size());
}

void Canvas::DrawXLine(uint16_t x, uint16_t y, uint16_t c)
{
  for (uint16_t i = 0; i < c; i++)
  {
    DrawPixel(x + i, y);
  }
}

void Canvas::DrawYLine(uint16_t x, uint16_t y, uint16_t c)
{
  for (uint16_t i = 0; i < c; i++)
  {
    DrawPixel(x, y + i);
  }
}

}

#endif