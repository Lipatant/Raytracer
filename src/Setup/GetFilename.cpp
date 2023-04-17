/*
** EPITECH PROJECT, 2023
** GetFilename.cpp
** File description:
** Checks if the user entered a corred amount of arguments
*/

#include "nts/Exception.hpp"

std::string setupGetFilename(int const ac, char const * const * const av)
{
    if (ac != 2)
        throw nts::exception::usage::InvalidAmountArguments();
    return (std::string)av[1];
}
