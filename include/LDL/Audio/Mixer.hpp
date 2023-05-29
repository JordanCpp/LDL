#ifndef LDL_Audio_Mixer_hpp
#define LDL_Audio_Mixer_hpp

#include <LDL/Core/FastPimpl.hpp>
#include <LDL/Graphics/Window.hpp>

namespace LDL
{
	namespace Audio
	{
		class MixerImpl;

		class LDL_EXPORT Mixer : public Core::FastPimpl
		{
		public:
			Mixer(Graphics::Window* window, size_t rate, size_t bits, size_t channels);
			MixerImpl* GetMixerImpl();
		private:
			MixerImpl* _MixerImpl;
		};
	}
}

#endif    