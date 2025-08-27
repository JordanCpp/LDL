// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Loaders_LocationLoader_hpp
#define Arcanum_Loaders_LocationLoader_hpp

#include <Arcanum/Objects/LocationCreator.hpp>
#include <Arcanum/Readers/XmlReader.hpp>

namespace Arcanum
{
	class LocationLoader
	{
	public:
		LocationLoader(XmlReader* xmlReader, LocationCreator* locationCreator);
		void Reset(const std::string& path);
	private:
		XmlReader*       _xmlReader;
		LocationCreator* _locationCreator;
		size_t           _sceneryCount;
	};
}

#endif  
