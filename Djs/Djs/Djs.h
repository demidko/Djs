#pragma once
#include <string_view>
#include <optional>
#include <map>
#include <vector>

namespace Djs {

    enum class Type
    {
        Json, // {"key": "value"}
        String, // "str"
        Boolean, // true false
        Null, // null
        Array, // []
        Number, // 1 2 3 
        Unknown
    };

    class Value
    {
        Type JsonType;
        std::optional<double> AsNumber;
        std::optional<std::string> AsString;
        std::optional<bool> AsBoolean;
        std::optional<nullptr_t> AsNull;
        std::optional<std::vector<Json>> AsArray;
        std::optional<std::map<std::string, Json>> AsObject;
    };

    struct Json
    {
        Value JsonValue;

        bool KeyExists(const std::string_view key) const;
        bool ValueExists(const std::string_view key) const;

        const std::optional<Json> &operator[](const std::string_view) const;

        static std::optional<Json> From(const std::string_view str);

    };


}