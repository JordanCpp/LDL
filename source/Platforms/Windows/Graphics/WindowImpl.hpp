#ifndef LDL_Platforms_Windows_Graphics_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_WindowImpl_hpp

#ifdef LDL_RENDER_SOFTWARE
#include "Software/WindowImpl.hpp"
#elif LDL_RENDER_GDI
#include "GDI/WindowImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/WindowImpl.hpp"
#elif LDL_RENDER_OPENGL3
#include "OpenGL3/WindowImpl.hpp"
#elif LDL_RENDER_DIRECT_DRAW
#include "DirectDraw/WindowImpl.hpp"
#elif LDL_RENDER_DIRECTX5
#include "DirectX5/Direct3D/WindowImpl.hpp"
#elif LDL_RENDER_DIRECTX9
#include "DirectX9/Direct3D/WindowImpl.hpp"
#elif LDL_RENDER_DIRECTX10
#include "DirectX10/Direct3D/WindowImpl.hpp"
#endif

#endif   