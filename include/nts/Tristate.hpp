/*
** EPITECH PROJECT, 2023
** nts/Tristate.hpp
** File description:
** Defines the logic for pins
*/

#pragma once
#include <iostream>

namespace nts
{
    enum class Tristate
    {
        False,
        True,
        Undefined,
    };
}

std::ostream &operator<<(std::ostream &s, nts::Tristate v);
