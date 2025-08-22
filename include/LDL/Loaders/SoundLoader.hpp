// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Loaders_SoundLoader_hpp
#define LDL_Loaders_SoundLoader_hpp

#include <string>
#include <LDL/Allocators/Allocator.hpp>

namespace LDL
{
	namespace Loaders
	{
		class LDL_LIBRARY SoundLoader
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
			Allocators::Allocator* _allocator;
			size_t                 _channels;
			size_t                 _rate;
			size_t                 _samples;
			uint8_t*               _bytes;
		};
	}
}

#endif      
