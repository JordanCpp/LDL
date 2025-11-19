// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Math_Random_hpp
#define LDL_Math_Random_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>

class LDL_LIBRARY LDL_Random
{
public:
    LDL_Random();
    LDL_Random(size_t seed);
    void Seed(size_t seed);
    size_t GetSeed() const;
    int Range(int min, int max);
    size_t Range(size_t min, size_t max);
    float Float();
    float Range(float min, float max);
private:
    size_t _seed;
};

#endif
