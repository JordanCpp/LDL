// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef std_fstream_hpp
#define std_fstream_hpp

#include <stdio.h>

namespace std
{
	class ios
	{
	public:
		static constexpr int in     = 0x01;
		static constexpr int out    = 0x02;
		static constexpr int ate    = 0x04;
		static constexpr int app    = 0x08;
		static constexpr int trunc  = 0x10;
		static constexpr int binary = 0x20;
	};

	class fstream
	{
	private:
		FILE* _file;

	public:
		fstream();
		fstream(const char* path, int mode = 0);
		bool open(const char* path, int mode);
		bool is_open();
		void close();
	};
}

#endif
