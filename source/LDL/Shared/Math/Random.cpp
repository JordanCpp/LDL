// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/std/stdint.hpp>
#include <LDL/Math/Random.hpp>
#include <time.h>

using namespace LDL::Math;

// LCG Parameters (from Numerical Recipes / glibc)
static const size_t LCG_MULTIPLIER = 1664525UL;
static const size_t LCG_INCREMENT  = 1013904223UL;

// For float generation: use 24 bits (single-precision mantissa)
static const uint32_t FLOAT_BIT_MASK   = 0xFFFFFF;     // 2^24 - 1
static const float    FLOAT_NORMALIZER = 16777216.0f;  // 2^24

Random::Random()
{
    Seed((size_t)(time(NULL)));
}

Random::Random(size_t seed)
{
    Seed(seed);
}

void Random::Seed(size_t seed)
{
    _seed = seed ? seed : 1;
}

size_t Random::GetSeed() const
{
    return _seed;
}

int Random::Range(int min, int max)
{
    if (min >= max)
    {
        return min;
    }

    _seed = LCG_MULTIPLIER * _seed + LCG_INCREMENT;

    long range = (long)(max - min + 1);

    return min + (int)(_seed % range);
}

size_t Random::Range(size_t min, size_t max)
{
    if (min >= max)
    {
        return min;
    }

    _seed = LCG_MULTIPLIER * _seed + LCG_INCREMENT;

    size_t range = max - min + 1;

    return min + (_seed % range);
}

float Random::Float()
{
    _seed = LCG_MULTIPLIER * _seed + LCG_INCREMENT;

    return ((float)(_seed & FLOAT_BIT_MASK)) / FLOAT_NORMALIZER;
}

float Random::Range(float min, float max)
{
    if (min >= max)
    {
        return min;
    }

    return min + (max - min) * Float();
}
