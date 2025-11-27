// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL4_6.hpp>
#include <LDL/OpenGL/GLLoad10.hpp>
#include <LDL/OpenGL/GLLoad11.hpp>
#include <LDL/OpenGL/GLLoad12.hpp>
#include <LDL/OpenGL/GLLoad13.hpp>
#include <LDL/OpenGL/GLLoad14.hpp>
#include <LDL/OpenGL/GLLoad15.hpp>
#include <LDL/OpenGL/GLLoad20.hpp>
#include <LDL/OpenGL/GLLoad21.hpp>
#include <LDL/OpenGL/GLLoad30.hpp>
#include <LDL/OpenGL/GLLoad31.hpp>
#include <LDL/OpenGL/GLLoad32.hpp>
#include <LDL/OpenGL/GLLoad33.hpp>
#include <LDL/OpenGL/GLLoad40.hpp>
#include <LDL/OpenGL/GLLoad41.hpp>
#include <LDL/OpenGL/GLLoad42.hpp>
#include <LDL/OpenGL/GLLoad43.hpp>
#include <LDL/OpenGL/GLLoad44.hpp>
#include <LDL/OpenGL/GLLoad45.hpp>
#include <LDL/OpenGL/GLLoad46.hpp>
#include <LDL/OpenGL/GLLoader.hpp>

LDL_OpenGLLoader::LDL_OpenGLLoader(LDL_Result& result) :
	_result(result),
	_functions(_result),
	_major(0),
	_minor(0)
{
}

LDL_OpenGLLoader::~LDL_OpenGLLoader()
{
}

bool LDL_OpenGLLoader::Init(size_t major, size_t minor)
{
	_major = major;
	_minor = minor;

	if (Equal(1, 0))
	{
		Init_1_0();
	}
	else if (Equal(1, 1))
	{
		Init_1_0();
		Init_1_1();
	}
	else if (Equal(1, 2))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
	}
	else if (Equal(1, 3))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
	}
	else if (Equal(1, 4))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
	}
	else if (Equal(1, 5))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
	}
	else if (Equal(2, 0))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
	}
	else if (Equal(2, 1))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
	}
	else if (Equal(3, 0))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
	}
	else if (Equal(3, 1))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
	}
	else if (Equal(3, 2))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
	}
	else if (Equal(3, 3))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
	}
	else if (Equal(4, 0))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
	}
	else if (Equal(4, 1))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
		Init_4_1();
	}
	else if (Equal(4, 2))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
		Init_4_1();
		Init_4_2();
	}
	else if (Equal(4, 3))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
		Init_4_1();
		Init_4_2();
		Init_4_3();
	}
	else if (Equal(4, 4))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
		Init_4_1();
		Init_4_2();
		Init_4_3();
		Init_4_4();
	}
	else if (Equal(4, 5))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
		Init_4_1();
		Init_4_2();
		Init_4_3();
		Init_4_4();
		Init_4_5();
	}
	else if (Equal(4, 6))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
		Init_4_1();
		Init_4_2();
		Init_4_3();
		Init_4_4();
		Init_4_6();
	}
	else
	{
		LDL_Formatter formatter;
		_result.Message(formatter.Format("OpenGL %d.%d not support", Major(), Minor()));

		return false;
	}

	return true;
}

bool LDL_OpenGLLoader::Equal(size_t major, size_t minor)
{
	return Major() == major && Minor() == minor;
}

size_t LDL_OpenGLLoader::Major()
{
	return _major;
}

size_t LDL_OpenGLLoader::Minor()
{
	return _minor;
}

void LDL_OpenGLLoader::Init_1_0()
{
	LDL_OpenGLLoader_1_0 loader(_result);
}

void LDL_OpenGLLoader::Init_1_1()
{
	LDL_OpenGLLoader_1_1 loader(_result);
}

void LDL_OpenGLLoader::Init_1_2()
{
	LDL_OpenGLLoader_1_2 loader(_result);
}

void LDL_OpenGLLoader::Init_1_3()
{
	LDL_OpenGLLoader_1_3 loader(_result);
}

void LDL_OpenGLLoader::Init_1_4()
{
	LDL_OpenGLLoader_1_4 loader(_result);
}

void LDL_OpenGLLoader::Init_1_5()
{
	LDL_OpenGLLoader_1_5 loader(_result);
}

void LDL_OpenGLLoader::Init_2_0()
{
	LDL_OpenGLLoader_2_0 loader(_result);
}

void LDL_OpenGLLoader::Init_2_1()
{
	LDL_OpenGLLoader_2_1 loader(_result);
}

void LDL_OpenGLLoader::Init_3_0()
{
	LDL_OpenGLLoader_3_0 loader(_result);
}

void LDL_OpenGLLoader::Init_3_1()
{
	LDL_OpenGLLoader_3_1 loader(_result);
}

void LDL_OpenGLLoader::Init_3_2()
{
	LDL_OpenGLLoader_3_2 loader(_result);
}

void LDL_OpenGLLoader::Init_3_3()
{
	LDL_OpenGLLoader_3_3 loader(_result);
}

void LDL_OpenGLLoader::Init_4_0()
{
	LDL_OpenGLLoader_4_0 loader(_result);
}

void LDL_OpenGLLoader::Init_4_1()
{
	LDL_OpenGLLoader_4_1 loader(_result);
}

void LDL_OpenGLLoader::Init_4_2()
{
	LDL_OpenGLLoader_4_2 loader(_result);
}

void LDL_OpenGLLoader::Init_4_3()
{
	LDL_OpenGLLoader_4_3 loader(_result);
}

void LDL_OpenGLLoader::Init_4_4()
{
	LDL_OpenGLLoader_4_4 loader(_result);
}

void LDL_OpenGLLoader::Init_4_5()
{
	LDL_OpenGLLoader_4_5 loader(_result);
}

void LDL_OpenGLLoader::Init_4_6()
{
	LDL_OpenGLLoader_4_6 loader(_result);
}
