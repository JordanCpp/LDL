#ifndef LDL_Audio_AudioContext_hpp
#define LDL_Audio_AudioContext_hpp

#include <LDL/Core/FastPimpl.hpp>
#include <LDL/Graphics/Window.hpp>

namespace LDL
{
	namespace Audio
	{
		class AudioContextImpl;

		class LDL_LIBRARY AudioContext : public LDL::Core::FastPimpl
		{
		public:
			AudioContext(LDL::Graphics::Window* window, size_t rate, size_t bits, size_t channels);
			~AudioContext();
			AudioContextImpl* GetAudioContextImpl();
			void* Context();
		private:
			AudioContextImpl* _AudioContextImpl;
		};
	}
}

#endif  
