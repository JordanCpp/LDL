#ifndef LDL_Loaders_SoundLoader_hpp
#define LDL_Loaders_SoundLoader_hpp

#include <LDL/Config.hpp>
#include <string>
#include <LDL/Allocators/Allocator.hpp>

namespace LDL
{
	namespace Loaders
	{
		class LDL_EXPORT SoundLoader
		{
		public:
			SoundLoader(Allocators::Allocator* allocator);
			~SoundLoader();
			void Clear();
			bool LoadOgg(const std::string& path);
			bool LoadWav(const std::string& path);
			bool LoadMp3(const std::string& path);
			bool LoadFlac(const std::string& path);
			bool Load(const std::string& path);
			Allocators::Allocator* Allocator();
			size_t Channels();
			size_t Rate();
			size_t Samples();
			uint8_t* Bytes();
		private:
			Allocators::Allocator* _Allocator;
			size_t _Channels;
			size_t _Rate;
			size_t _Samples;
			uint8_t* _Bytes;
		};
	}
}

#endif      