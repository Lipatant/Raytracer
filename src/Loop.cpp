/*
** EPITECH PROJECT, 2023
** Loop.cpp
** File description:
** You spin me right 'round, baby, right 'round
*/

#include <iostream>
#include <map>
#include <regex>
#include "nts/ComponentMap.hpp"
#include "nts/Exception.hpp"
#include "Utility/Regex.hpp"

bool loopDisplay(nts::ComponentMap &componentMap, std::string const &in, \
    size_t &tick);
bool loopExit(nts::ComponentMap &componentMap, std::string const &in, \
    size_t &tick);
bool loopInput(nts::ComponentMap &componentMap, std::string const &in, \
    size_t &tick);
bool loopLoop(nts::ComponentMap &componentMap, std::string const &in, \
    size_t &tick);
bool loopSimulate(nts::ComponentMap &componentMap, std::string const &in, \
    size_t &tick);

struct command_s {
    std::string regex;
    bool (*function) (nts::ComponentMap &, std::string const &, size_t &);
};

static const struct command_s COMMANDS[] {
    {"^\\s*exit\\s*$", loopExit},
    {"^\\s*display\\s*$", loopDisplay},
    {"^\\s*simulate\\s*$", loopSimulate},
    {"^\\s*loop\\s*$", loopLoop},
    {"^\\s*\\w+=[01U]\\s*$", loopInput},
};

static bool loopIteration(nts::ComponentMap &componentMap, size_t &tick)
{
    std::string input;
    size_t commandsSize = sizeof(COMMANDS) / sizeof(COMMANDS[0]);

    std::cout << "> ";
    std::getline(std::cin, input);
    if (std::cin.eof())
        return false;
    for (size_t i = 0; i < commandsSize; i++)
        if (utility::regex::quickTest(input, COMMANDS[i].regex))
            return COMMANDS[i].function(componentMap, input, tick);
    nts::drawException(nts::exception::UnknownCommand().what(), input);
    return true;
}

bool loop(nts::ComponentMap &componentMap)
{
    size_t tick = 0;

    while (loopIteration(componentMap, tick));
    return true;
}
