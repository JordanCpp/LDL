#ifndef Arcanum_Loaders_ArtLoader_hpp
#define Arcanum_Loaders_ArtLoader_hpp

#include <Arcanum/Formats/Art.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace Arcanum
{
	namespace Loaders
	{
		class ArtLoader
		{
		public:
			void Load(const std::string& path);
			const LDL::Graphics::Point2u& Size();
			const LDL::Graphics::Point2u& Offset();
			const LDL::Graphics::Point2u& Delta();
			uint8_t* Pixels();
			size_t Frames();
			void Frame(size_t index);
		private:
			ArtFile _File;
			LDL::Graphics::Point2u _Size;
			LDL::Graphics::Point2u _Offset;
			LDL::Graphics::Point2u _Delta;
			std::vector<uint8_t> _Pixels;
		};
	}
}

#endif    