/*
** EPITECH PROJECT, 2023
** nts/Instruction/Modes.hpp
** File description:
** -
*/

#pragma once
#include <iostream>
#include <map>

namespace nts
{
namespace instruction {
    enum class Mode {
        None, Chipset, Link, SIZE
    };

    static const std::map<std::string, nts::instruction::Mode> MODES {
        {"chipsets", nts::instruction::Mode::Chipset},
        {"links", nts::instruction::Mode::Link},
    };
}
}
