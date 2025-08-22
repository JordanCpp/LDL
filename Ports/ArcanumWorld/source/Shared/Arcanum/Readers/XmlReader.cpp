#include <Arcanum/Readers/XmlReader.hpp>
#include <cstdlib>
#include <iostream>

using namespace Arcanum::Readers;

XmlReader::XmlReader() :
    token(0),
    tabs(0),
    line(0),
    length(0),
    mode(0)
{
}

XmlReader::XmlReader(const std::string & name, size_t mode_open)
{
    Reset(name, mode_open);
}

XmlReader::~XmlReader()
{
    CloseFile();
}

bool XmlReader::Reset(const std::string & name, size_t mode_open)
{
    mode = mode_open;
    line = 1;
    tabs = 0;

    xml_data.clear();
    xml_name.clear();

    if (mode == XmlReader::FromFile)
    {
        input.open(name.c_str());

        if (!input.is_open())
        {
            return false;
        }
    }
    else if (mode == XmlReader::FromString)
    {
        xml_source = name;
        length = 0;
    }
    else
    {
        return false;
    }

    return true;
}

void XmlReader::CloseFile()
{
    if (input.is_open())
    {
        input.close();
    }
}

const std::string & XmlReader::Name()
{
    return xml_name;
}

const std::string & XmlReader::Value()
{
    return xml_data;
}

int XmlReader::ValueInt()
{
    return std::atoi(xml_data.c_str());
}

bool XmlReader::Eof()
{
    bool result = true;

    if (mode == XmlReader::FromFile)
    {
        result = input.eof();
    }
    else if (mode == XmlReader::FromString)
    {
        result = length >= xml_source.size();
    }

    return result;
}

char XmlReader::NextChar()
{
    char ch = 0;

    if (mode == XmlReader::FromString)
    {
        ch = xml_source[length];
        length++;
    }
    else if (mode == XmlReader::FromFile)
    {
        input.get(ch);
    }

    tabs++;

    if (ch == '\n')
    {
        tabs = 1;
        line++;
    }

    return ch;
}

bool XmlReader::Next()
{
    char ch = NextChar();

    while (isspace(ch))
    {
        ch = NextChar();
    }

    bool result = false;

    if (Eof())
    {
        result = false;
    }
    else if (ch == '<')
    {
        ch = NextChar();

        if (ch == '/')
        {
            token = XmlReader::Close;
            ch = NextChar();
        }
        else
        {
            token = XmlReader::Open;
        }

        xml_name.clear();

        while ((ch != '>') && (ch != '\n'))
        {
            xml_name.push_back(ch);
            ch = NextChar();
        }

        result = true;
    }
    else
    {
        token = XmlReader::Data;
        xml_data.clear();

        while ((ch != '<') && (ch != '\n'))
        {
            xml_data.push_back(ch);
            ch = NextChar();
        }

        if (ch == '<')
        {
            if (mode == XmlReader::FromFile)
            {
                input.unget();
            }
            else if (mode == XmlReader::FromString)
            {
                length--;
            }
        }

        result = true;
    }

    return result;
}

bool XmlReader::IsOpening(const std::string & name)
{
    return token == XmlReader::Open && Name() == name;
}

bool XmlReader::IsOpening()
{
    return token == XmlReader::Open;
}

bool XmlReader::IsClosing(const std::string & name)
{
    return token == XmlReader::Close && Name() == name;
}

bool XmlReader::IsClosing()
{
    return token == XmlReader::Close;
}

bool XmlReader::IsData()
{
    return (token == XmlReader::Data);
}

bool XmlReader::NextOpening(const std::string & name)
{
    bool result = (Next() && IsOpening(name));

    if (!result)
    {
        std::cout << "Not found: <" <<  name << ">" << '\n';
        std::terminate();
    }

    return result;
}

bool XmlReader::NextOpening()
{
    bool result = (Next() && IsOpening());

    return result;
}

bool XmlReader::NextClosing(const std::string & name)
{
    bool result = (Next() && IsClosing(name));

    if (!result)
    {
        std::cout << "Not found: </" <<  name << ">" << '\n';
        std::terminate();
    }

    return result;
}

bool XmlReader::NextClosing()
{
    bool result = (Next() && IsClosing());

    return result;
}

bool XmlReader::NextValue()
{
    bool result = (Next() && IsData());

    if (!result)
    {
        std::cout << "Not found: Value" << '\n';
        std::terminate();
    }

    return result;
}

bool XmlReader::NextNode(const std::string & name)
{
    bool result = false;

    if (NextOpening(name))
    {
        if (NextValue())
        {
            if (NextClosing(name))
            {
                result = true;
            }
        }
    }

    return result;
}

bool XmlReader::NextNode()
{
    bool result = false;

    if (NextOpening())
    {
        if (NextValue())
        {
            if (NextClosing())
            {
                result = true;
            }
        }
    }

    return result;
}

void XmlReader::AssertClosing(const std::string & name)
{
    if (IsClosing(name) != true)
    {
        std::cout << "Not found: </" << name << ">" << '\n';
        std::terminate();
    }
}

void XmlReader::AssertOpening(const std::string & name)
{
    if (IsOpening(name) != true)
    {
        std::cout << "Not found opening: <" << name << ">" << '\n';
        std::terminate();
    }
}

bool XmlReader::IsPercent(const std::string & value)
{
    size_t found = value.find('%');

    return found != std::string::npos;
}

int XmlReader::ParsePercent(const std::string & value)
{
    std::string number;

    size_t found = value.find('%');

    if (found != std::string::npos)
    {
        for (size_t i = 0; i < found; i++)
        {
            number.push_back(value[i]);
        }

        return std::atoi(number.c_str());
    }

    return std::atoi(value.c_str());
}

void XmlReader::Error(const std::string & desc)
{
    std::cout << desc << '\n';
    std::terminate();
}
