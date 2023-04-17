/*
** EPITECH PROJECT, 2023
** nts/Exception.cpp
** File description:
** Used for error handling
*/

#include "nts/Exception.hpp"

namespace nts
{
    bool drawException(char const *what, std::string const &content)
    {
        if (content.empty())
            return drawException(what);
        std::cerr << what << " '" << content << "'." << std::endl;
        return false;
    }

    bool drawException(char const *what)
    {
        std::cerr << what << std::endl;
        return false;
    }
}
