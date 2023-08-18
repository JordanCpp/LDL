#ifndef Arcanum_Readers_MesReader_hpp
#define Arcanum_Readers_MesReader_hpp

#include <string>
#include <fstream>

namespace Arcanum
{
	namespace Readers
	{
		class MesReader
		{
		public:
			void Reset(const std::string& path);
			void Close();
			char NextChar();
			bool Next();
			const std::string& Result();
			bool Eof();
		private:
			std::ifstream _File;
			std::string   _Result;
			size_t        _Tabs;
			size_t        _Line;
		};
	}
}

#endif    