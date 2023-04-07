#ifndef LDL_Audio_DirectSound8_MixerImpl_hpp
#define LDL_Audio_DirectSound8_MixerImpl_hpp

#include <LDL/Audio/Mixer.hpp>
#include <LDL/Graphics/Window.hpp>
#include <dsound.h>

namespace LDL
{
	namespace Audio
	{
		class MixerImpl
		{
		public:
			MixerImpl(LDL::Graphics::Window* window, size_t rate, size_t bits, size_t channels);
			~MixerImpl();
		private:
			LDL::Graphics::Window* _Window;
			IDirectSound8* _DirectSound;
			IDirectSoundBuffer* _DirectPrimaryBuffer;
			IDirectSoundBuffer8* _DirectSoundBuffer;

		};
	}
}

#endif    