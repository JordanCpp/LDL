// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Linux_Graphics_Glide_WindowImplGlide_hpp
#define LDL_Platforms_Linux_Graphics_Glide_WindowImplGlide_hpp

#include <LDL/APIs/OpenGL/OpenGLLoader.hpp>
#include "../MainWindow.hpp"
#include "../../../WindowImpl.hpp"
#include "../GLX.hpp"

namespace LDL
{
	namespace Graphics
	{
		class WindowImplGlide : public WindowImpl
		{
		public:
			WindowImplGlide(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~WindowImplGlide();
			void Present(uint8_t* pixels, uint8_t bytesPerPixel);
			void Present();
			bool Running();
			void PollEvents();
			bool GetEvent(LDL::Events::Event& event);
			bool WaitEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Vec2u& Size();
			const Vec2u& Pos();
			void* NativeHandle();
		private:
		    MainWindow   _Window;
			XVisualInfo* _Visual;
			GLXContext   _Context;
			OpenGLLoader _OpenGLLoader;
		};
	}
}

#endif    
