/*
** EPITECH PROJECT, 2022
** Argument/Argument/Set.cpp
** File description:
** Set.cpp
*/

#include "Argument/Argument.hpp"
#include <iostream>
#include <map>

static void assignFov(Arg::Argument &arg, std::string const &value)
{
    arg.fov = std::stod(value);
}

static void assignWidth(Arg::Argument &arg, std::string const &value)
{
    arg.width = std::stoul(value);
}

static void assignOut(Arg::Argument &arg, std::string const &value)
{
    arg.out = value;
}

static void assignHeight(Arg::Argument &arg, std::string const &value)
{
    arg.height = std::stoul(value);
}

static void assignRebound(Arg::Argument &arg, std::string const &value)
{
    arg.rebound = std::stoul(value);
}

static void assignBlending(Arg::Argument &arg, std::string const &value)
{
    arg.blending = std::stoul(value);
}

static const std::map<std::string const, void (*)(Arg::Argument &arg, \
    std::string const &)> ARGUMENT_MAP = {
    {"-b", assignBlending},
    {"--blending", assignBlending},
    {"-f", assignFov},
    {"--fov", assignFov},
    {"-h", assignHeight},
    {"--height", assignHeight},
    {"-o", assignOut},
    {"--out", assignOut},
    {"-r", assignRebound},
    {"--rebound", assignRebound},
    {"-w", assignWidth},
    {"--width", assignWidth},
};

static bool displayErrorKey(std::string const &key)
{
    std::cerr << "Invalid key '" << key << "'" << std::endl;
    return false;
}

static bool displayErrorCount(void)
{
    std::cerr << "Invalid amount of arguments" << std::endl;
    return false;
}

bool Arg::Argument::setArguments(int const ac, char const * const * const av)
{
    std::string key;

    if (ac % 2 == 0)
        return displayErrorCount();
    for (int i = 1; (i + 1) < ac; i += 2) {
        key = av[i];
        if (ARGUMENT_MAP.find(key) == ARGUMENT_MAP.end())
            return displayErrorKey(key);
        ARGUMENT_MAP.at(key)(*this, av[i + 1]);
    }
    return true;
}
