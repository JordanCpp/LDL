#ifndef Arcanum_Loaders_ArtLoader_hpp
#define Arcanum_Loaders_ArtLoader_hpp

#include <LDL/Math/Vec2.hpp>
#include <Arcanum/Formats/Art.hpp>
#include <Arcanum/Readers/MemoryReader.hpp>

namespace Arcanum
{
	namespace Loaders
	{
		class ArtLoader
		{
		public:
			void Load(Readers::MemoryReader& memoryReader);
			const LDL::Vec2u& Size();
			const LDL::Vec2u& Offset();
			const LDL::Vec2u& Delta();
			uint8_t* Pixels();
			size_t Frames();
			void Frame(size_t index);
		private:
			ArtFile              _file;
			LDL::Vec2u           _size;
			LDL::Vec2u           _offset;
			LDL::Vec2u           _delta;
			std::vector<uint8_t> _pixels;
		};
	}
}

#endif    