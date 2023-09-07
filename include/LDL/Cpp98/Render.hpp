#ifndef LDL_Cpp98_Render_hpp
#define LDL_Cpp98_Render_hpp

#include <LDL/Creators.hpp>

namespace LDL
{
	namespace Graphics
	{
		class Render
		{
		public:
			Render()
			{
				_Render = RenderCreate();
			}

			~Render()
			{
				Destroy(_Render);
			}

			void Draw()
			{
				_Render->Draw();
			}
		private:
			LDL_IRender* _Render;
		};
	}
}

#endif
