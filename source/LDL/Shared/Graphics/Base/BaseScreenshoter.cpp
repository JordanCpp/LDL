#include <LDL/Shared/Graphics/Base/BaseScreenshoter.hpp>
#include <time.h>

using namespace LDL::Graphics;

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
