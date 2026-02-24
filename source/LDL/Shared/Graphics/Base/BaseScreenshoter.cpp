// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <time.h>
#include <LDL/Shared/Graphics/Base/BaseScreenshoter.hpp>

using namespace LDL;

const std::string BaseScreenShotter::Prefix()
{
    time_t     rawTime;
    struct tm* timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    _prefix = "";

    _prefix += _converter.ToString(timeInfo->tm_mday);

    _prefix += '.';
    _prefix += _converter.ToString(timeInfo->tm_mon + 1);

    _prefix += '.';
    _prefix += _converter.ToString(timeInfo->tm_year + 1900);

    _prefix += '-';
    _prefix += _converter.ToString(timeInfo->tm_hour);

    _prefix += '.';
    _prefix += _converter.ToString(timeInfo->tm_min);

    _prefix += '.';
    _prefix += _converter.ToString(timeInfo->tm_sec);

    return _prefix;
}
