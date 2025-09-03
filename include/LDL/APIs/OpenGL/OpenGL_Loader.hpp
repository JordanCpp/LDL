// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_OpenGL_OpenGL_Loader_hpp
#define LDL_APIs_OpenGL_OpenGL_Loader_hpp

#include <LDL/std/stddef.hpp>
#include <LDL/std/stdbool.hpp>
#include <LDL/APIs/OpenGL/OpenGL_Functions.hpp>

namespace LDL
{
	class LDL_LIBRARY OpenGLLoader
	{
	public:
		OpenGLLoader();
		OpenGLLoader(size_t major, size_t minor);
		~OpenGLLoader();
		void Init(size_t major, size_t minor);
		bool Equal(size_t major, size_t minor);
		size_t Major();
		size_t Minor();
		void Init_1_0();
		void Init_1_1();
		void Init_1_2();
		void Init_1_3();
		void Init_1_4();
		void Init_1_5();
		void Init_2_0();
		void Init_2_1();
		void Init_3_0();
		void Init_3_1();
		void Init_3_2();
		void Init_3_3();
		void Init_4_0();
		void Init_4_1();
		void Init_4_2();
		void Init_4_3();
		void Init_4_4();
		void Init_4_5();
		void Init_4_6();
	private:
		LDL::OpenGLFunctions _Functions;
		size_t _Major;
		size_t _Minor;
	};
}

#endif   
