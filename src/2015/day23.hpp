#pragma once
#include <array>
#include <string_view>

namespace input
{
    using namespace std::string_view_literals;
    static constexpr std::array instructions{
        "jio a, +16"sv, "inc a"sv, "inc a"sv, "tpl a"sv,  "tpl a"sv, "tpl a"sv,  "inc a"sv,     "inc a"sv,
        "tpl a"sv,      "inc a"sv, "inc a"sv, "tpl a"sv,  "tpl a"sv, "tpl a"sv,  "inc a"sv,     "jmp +23"sv,
        "tpl a"sv,      "inc a"sv, "inc a"sv, "tpl a"sv,  "inc a"sv, "inc a"sv,  "tpl a"sv,     "tpl a"sv,
        "inc a"sv,      "inc a"sv, "tpl a"sv, "inc a"sv,  "tpl a"sv, "inc a"sv,  "tpl a"sv,     "inc a"sv,
        "inc a"sv,      "tpl a"sv, "inc a"sv, "tpl a"sv,  "tpl a"sv, "inc a"sv,  "jio a, +8"sv, "inc b"sv,
        "jie a, +4"sv,  "tpl a"sv, "inc a"sv, "jmp +2"sv, "hlf a"sv, "jmp -7"sv,
    };
}
