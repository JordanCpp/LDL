#include <LDL/Core/RuntimeError.hpp>
#include "MixerImpl.hpp"
#include <LDL/Graphics/Window.hpp>
#include "../../Platforms/Windows/Graphics/WindowImpl.hpp"

using namespace LDL::Audio;
using namespace LDL::Core;

MixerImpl::MixerImpl(LDL::Graphics::Window* window, size_t rate, size_t bits, size_t channels) :
	_Window(window),
{
}

MixerImpl::~MixerImpl()
{
}