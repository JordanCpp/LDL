// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Audio/Mixer.hpp>

using namespace LDL::Core;
using namespace LDL::Graphics;
using namespace LDL::Audio;
using namespace LDL::Math;

int main()
{
	Result result;
	RenderContext renderContext;

	Window window(result, renderContext, Vec2u(1, 2), Vec2u(640, 480), "Mixer.cpp");
	AudioContext audioContext(&window, 44100, 16, 2);

	return 0;
}
