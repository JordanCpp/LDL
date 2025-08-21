#include "BaseScreenshoter.hpp"
#include <time.h>

using namespace LDL::Graphics;

const std::string BaseScreenshoter::Prefix()
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    _Prefix = "";

    _Prefix += _Converter.Convert(timeinfo->tm_mday);

    _Prefix += '.';
    _Prefix += _Converter.Convert(timeinfo->tm_mon + 1);

    _Prefix += '.';
    _Prefix += _Converter.Convert(timeinfo->tm_year + 1900);

    _Prefix += '-';
    _Prefix += _Converter.Convert(timeinfo->tm_hour);

    _Prefix += '.';
    _Prefix += _Converter.Convert(timeinfo->tm_min);

    _Prefix += '.';
    _Prefix += _Converter.Convert(timeinfo->tm_sec);

    return _Prefix;
}
