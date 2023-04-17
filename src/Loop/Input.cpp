/*
** EPITECH PROJECT, 2023
** Loop/Input.cpp
** File description:
** -
*/

#include <iostream>
#include "nts/ComponentMap.hpp"
#include "nts/Exception.hpp"
#include "nts/Tristate.hpp"
#include "Utility/Regex.hpp"

static nts::Tristate convertValue(std::string const &str)
{
    if (str == "0")
        return nts::Tristate::False;
    if (str == "1")
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}

bool loopInput(nts::ComponentMap &componentMap, std::string const &in, \
    size_t &tick)
{
    std::string name = utility::regex::firstMatch(in, "\\w+(?==[01U]\\s*$)");
    std::string value = utility::regex::firstMatch(in, "[01U](?=\\s*$)");

    if (!componentMap.isKey(name))
        return !nts::drawException(nts::exception::parsing:: \
            UnknownComponentName().what(), name);
    if (!componentMap.getValue(name)->isInput())
        return !nts::drawException(nts::exception:: \
            ComponentNotInput().what(), name);
    componentMap.getValue(name)->setState(convertValue(value));
    return true;
}
