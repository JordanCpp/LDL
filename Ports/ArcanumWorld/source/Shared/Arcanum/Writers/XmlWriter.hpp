#ifndef Arcanum_Writters_XmlWriter_hpp
#define Arcanum_Writters_XmlWriter_hpp

#include <fstream>
#include <string>
#include <LDL/Core/Convert.hpp>

namespace Arcanum
{
	namespace Writers
	{
		class XmlWriter
		{
		public:
			~XmlWriter();
			bool Reset(const std::string& path);
			void Close();
			void TagBegin(const std::string& name);
			void TagEnd(const std::string& name);
			void Node(const std::string& name, const std::string& data);
			void Node(const std::string& name, intmax_t data);
		private:
			std::ofstream  _file;
			LDL::Convert   _convert;
		};
	}
}

#endif    