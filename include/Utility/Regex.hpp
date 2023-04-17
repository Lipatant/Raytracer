/*
** EPITECH PROJECT, 2023
** Utility/Regex.hpp
** File description:
** -
*/

#pragma once
#include <iostream>
#include <regex>

namespace utility
{
namespace regex
{
    /// @brief Gets the first occurence of a regex
    /// @param string std::string to test on
    /// @param regex regex to use
    /// @return First string found
    std::string firstMatch(std::string const &string, std::regex const &regex);

    /// @brief Gets the first occurence of a regex
    /// @param string std::string to test on
    /// @param regexString regex to use
    /// @return First string found
    std::string firstMatch(std::string const &string, std::string const &regexString);

    /// @brief Checks if a regex can be applaied to a string
    /// @param string std::string to test on
    /// @param regex regex to test
    /// @return true or false
    bool quickTest(std::string const &string, std::regex const &regex);

    /// @brief Checks if a regex can be applaied to a string
    /// @param string std::string to test on
    /// @param regexString regex to test
    /// @return true or false
    bool quickTest(std::string const &string, std::string const &regexString);
}
}
