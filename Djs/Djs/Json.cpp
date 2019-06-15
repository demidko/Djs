#include "Json.h"
#include <cctype>

namespace
{
    using Iter = std::string_view::const_iterator;
    using Djs::Type;

    std::string_view::const_iterator SkipSpaces(Iter i, const Iter &end)
    {
        for (; i < end; ++i)
        {
            if (!std::isspace(*i))
            {
                return i;
            }
        }
        return end;
    }

    

    Type WhatIsIt(char i)
    {
        if (i == '"') { return Type::String; }
        if (std::isdigit(i)) { return Type::Number; }
        if (std::isalpha(i)) 
        {
            if (i == 't' || i == 'f') { return Type::Boolean; }
            if (i == 'n') { return Type::Null; }
            return Type::Unknown;
        }
        if (i == '{') { return Type::Json; }
        if (i == '[') { return Type::Array; }
        return Type::Unknown;
    }

    std::vector<Json> Array(Iter i, const Iter &end)
    {
        size_t brackets = 1;
        while (brackets >= 0)
        {

        }
    }
}


std::optional<Json> Json::From(const std::string_view str)
{
    const auto end = cend(str);
    auto i = SkipSpaces(cbegin(str), end);
    if (i == end)
    {
        return {};
    }
    /*switch (WhatIsIt(*i))
    {
    case Type::Array:

    }*/
    return {};
}
