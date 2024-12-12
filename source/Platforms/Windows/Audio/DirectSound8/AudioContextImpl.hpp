#ifndef LDL_Platforms_Windows_Audio_DirectSound8_AudioContextImpl_hpp
#define LDL_Platforms_Windows_Audio_DirectSound8_AudioContextImpl_hpp

#include <LDL/Audio/AudioContext.hpp>
#include "../source/Platforms/Windows/DirectX/DirectSound8.hpp"

namespace LDL
{
	namespace Audio
	{
		class AudioContextImpl
		{
		public:
			AudioContextImpl(LDL::Graphics::Window* window, size_t rate, size_t bits, size_t channels);
			~AudioContextImpl();
			size_t Rate();
			size_t Bits();
			size_t Channels();
		private:
			size_t _rate;
			size_t _bits; 
			size_t _channels;
		public:
			IDirectSound8*      _directSound;
			IDirectSoundBuffer* _primaryBuffer;
		};
	}
}

#endif  
