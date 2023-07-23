#ifndef LDL_Text_Rasterizer_hpp
#define LDL_Text_Rasterizer_hpp

#include <LDL/Text/Font.hpp>
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/Color.hpp>
#include <string>

namespace LDL
{
	namespace Text
	{
		class RasterizerImpl;

		class LDL_EXPORT Rasterizer : public LDL::Core::FastPimpl
		{
		public:
			Rasterizer(const Math::Vec2u& bufferSize);
			~Rasterizer();
			RasterizerImpl* GetRasterizerImpl();
			Graphics::Surface* Result();
			bool RenderText(const std::string& text, Font* font, const Graphics::Color& color);
		private:
			RasterizerImpl* _RasterizerImpl;
		};
	}
}

#endif    
