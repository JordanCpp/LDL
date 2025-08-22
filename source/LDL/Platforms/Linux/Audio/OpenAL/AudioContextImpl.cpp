// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "AudioContextImpl.hpp"
#include <LDL/Graphics/Window.hpp>
#include <LDL/Core/Library.hpp>

using namespace LDL::Audio;
using namespace LDL::Core;
using namespace LDL::Graphics;

AudioContextImpl::AudioContextImpl(Window* window, size_t rate, size_t bits, size_t channels) :
	_Rate(rate),
	_Bits(bits),
	_Channels(channels)
{
}

AudioContextImpl::~AudioContextImpl()
{
}

size_t AudioContextImpl::Rate()
{
	return _Rate;
}

size_t AudioContextImpl::Bits()
{
	return _Bits;
}

size_t AudioContextImpl::Channels()
{
	return _Channels;
}