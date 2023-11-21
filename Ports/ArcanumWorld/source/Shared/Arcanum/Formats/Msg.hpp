#ifndef Arcanum_Formats_Msg_hpp
#define Arcanum_Formats_Msg_hpp

#include <string>

namespace Arcanum
{
	namespace Formats
	{
		class Msg
		{
		public:
			size_t Number();
			void Number(size_t value);

			const std::string& Content();
			void Content(const std::string& value);
		private:
			size_t _Number;
			std::string _Content;
		};
	}
}

#endif