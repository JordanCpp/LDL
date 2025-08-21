#ifndef Arcanum_Loaders_ArtLoader_hpp
#define Arcanum_Loaders_ArtLoader_hpp

#include <Arcanum/Formats/Art.hpp>
#include <LDL/Math/Vec2.hpp>
#include <Arcanum/Readers/MemoryReader.hpp>

namespace Arcanum
{
	namespace Loaders
	{
		class ArtLoader
		{
		public:
			void Load(Readers::MemoryReader& memoryReader);
			const LDL::Math::Vec2u& Size();
			const LDL::Math::Vec2u& Offset();
			const LDL::Math::Vec2u& Delta();
			uint8_t* Pixels();
			size_t Frames();
			void Frame(size_t index);
		private:
			Formats::ArtFile     _file;
			LDL::Math::Vec2u     _size;
			LDL::Math::Vec2u     _offset;
			LDL::Math::Vec2u     _delta;
			std::vector<uint8_t> _pixels;
		};
	}
}

#endif    