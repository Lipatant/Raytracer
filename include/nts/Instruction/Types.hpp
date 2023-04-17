/*
** EPITECH PROJECT, 2023
** nts/Instruction/Types.hpp
** File description:
** -
*/

#pragma once
#include <iostream>

namespace nts
{
namespace instruction {
    enum class Type {
        Comment, Statement, Chipset, Link, SIZE
    };

    using Comment = bool;

    using Statement = struct Statement_s {
        std::string content;
    };

    using Chipset = struct Chipset_s {
        std::string name;
        std::string type;
    };

    using Link = struct Link_s {
        std::string source;
        size_t source_pin;
        std::string target;
        size_t target_pin;
    };
}
}
