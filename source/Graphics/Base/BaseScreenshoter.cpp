#include <LDL/Graphics/Base/BaseScreenshoter.hpp>
#include <ctime>

const std::string LDL::Graphics::BaseScreenshoter::Prefix()
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    _Prefix.clear();

    if (_Converter.Convert(timeinfo->tm_mday))
    _Prefix += _Converter.Result();

    _Prefix += '.';

    if (_Converter.Convert(timeinfo->tm_mon + 1))
        _Prefix += _Converter.Result();

    _Prefix += '.';

    if (_Converter.Convert(timeinfo->tm_year + 1900))
        _Prefix += _Converter.Result();

    _Prefix += '-';
    if (_Converter.Convert(timeinfo->tm_hour))
        _Prefix += _Converter.Result();

    _Prefix += '.';
    if (_Converter.Convert(timeinfo->tm_min))
        _Prefix += _Converter.Result();

    _Prefix += '.';
    if (_Converter.Convert(timeinfo->tm_sec))
        _Prefix += _Converter.Result();

    return _Prefix;
}