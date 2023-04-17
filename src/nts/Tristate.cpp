/*
** EPITECH PROJECT, 2023
** nts/Tristate.cpp
** File description:
** Defines the logic for pins
*/

#include "nts/Tristate.hpp"

std::ostream &operator<<(std::ostream &s, nts::Tristate v)
{
    if (v == nts::Tristate::Undefined)
        s << "undefined";
    else
        s << (v == nts::Tristate::True ? '1' : '0');
    return s;
}
