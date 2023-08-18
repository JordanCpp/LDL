#ifndef Arcanum_Writters_XmlWritter_hpp
#define Arcanum_Writters_XmlWritter_hpp

#include <fstream>
#include <string>
#include <LDL/Core/NumberToString.hpp>

namespace Arcanum
{
	namespace Writters
	{
		class XmlWritter
		{
		public:
			~XmlWritter();
			bool Reset(const std::string& path);
			void Close();
			void TagBegin(const std::string& name);
			void TagEnd(const std::string& name);
			void Node(const std::string& name, const std::string& data);
			void Node(const std::string& name, intmax_t data);
		private:
			std::ofstream _File;
			LDL::Core::NumberToString _NumberToString;
		};
	}
}

#endif    