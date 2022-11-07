#include <LDL/Graphics/Base/BaseScreenshoter.hpp>
#include <ctime>

const std::string LDL::Graphics::BaseScreenshoter::Prefix()
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    _Prefix.clear();

    _Prefix += timeinfo->tm_mday;
    _Prefix += '.';
    _Prefix += timeinfo->tm_mon + 1;
    _Prefix += '.';
    _Prefix += timeinfo->tm_year + 1900;
    _Prefix += '-';
    _Prefix += timeinfo->tm_hour;
    _Prefix += '.';
    _Prefix += timeinfo->tm_min;
    _Prefix += '.';
    _Prefix += timeinfo->tm_sec;

    return _Prefix;
}