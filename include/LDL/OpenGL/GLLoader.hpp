// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_GLLoader_hpp
#define LDL_GLLoader_hpp

#include <LDL/Types.hpp>
#include <LDL/OpenGL/GLFuncs.hpp>

class LDL_LIBRARY LDL_OpenGLLoader
{
public:
	LDL_OpenGLLoader(LDL_Result& result);
	~LDL_OpenGLLoader();
	bool Init(size_t major, size_t minor);
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
	LDL_Result&         _result;
	LDL_OpenGLFunctions _functions;
	size_t              _major;
	size_t              _minor;
};

#endif   
