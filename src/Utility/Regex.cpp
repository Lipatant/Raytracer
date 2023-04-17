/*
** EPITECH PROJECT, 2023
** Regex.cpp
** File description:
** -
*/

#include "Utility/Regex.hpp"

namespace utility {
namespace regex {
    std::string firstMatch(std::string const &string, std::regex const &regex)
    {
        std::smatch smatch;

        if (!std::regex_search(string, smatch, regex))
            return "";
        return smatch.str(0);
    }

    std::string firstMatch(std::string const &string, std::string const \
        &regexString)
    {
        std::regex regexConverted(regexString);

        return firstMatch(string, regexConverted);
    }

    bool quickTest(std::string const &string, std::regex const &regex)
    {
        return regex_match(string, regex);
    }

    bool quickTest(std::string const &string, std::string const &regexString)
    {
        std::regex regexConverted(regexString);

        return regex_match(string, regexConverted);
    }
}
}
