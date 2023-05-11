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

static void assignScene(Arg::Argument &arg, std::string const &value)
{
    arg.fileScene = value;
}

static void triggerAskUsage(Arg::Argument &arg)
{
    arg.askUsage = true;
}

static void triggerNoConsole(Arg::Argument &arg)
{
    arg.noConsole = true;
}

static void triggerAlphadup(Arg::Argument &arg)
{
    arg.alphadup = true;
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

static const std::map<std::string const, void (*)(Arg::Argument &arg)> \
    TRIGGER_MAP = {
    {"--alphadub", triggerAlphadup},
    {"--noconsole", triggerNoConsole},
};

static const std::map<std::string const, void (*)(Arg::Argument &arg)> \
    TRIGGER_MAP_DEFAULT = {
    {"-h", triggerAskUsage},
    {"--help", triggerAskUsage},
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

    if (ac < 2)
        return displayErrorCount();
    if (TRIGGER_MAP_DEFAULT.find(av[1]) != TRIGGER_MAP_DEFAULT.end()) {
        TRIGGER_MAP_DEFAULT.at(av[1])(*this);
        return true;
    }
    assignScene(*this, av[1]);
    for (int i = 2; i < ac; i++) {
        key = av[i];
        if (ARGUMENT_MAP.find(key) != ARGUMENT_MAP.end()) {
            if (i + 1 >= ac)
                return displayErrorCount();
            ARGUMENT_MAP.at(key)(*this, av[i + 1]);
            i++;
        } else if (TRIGGER_MAP.find(key) != TRIGGER_MAP.end())
            TRIGGER_MAP.at(key)(*this);
        else if (TRIGGER_MAP_DEFAULT.find(key) != TRIGGER_MAP_DEFAULT.end())
            TRIGGER_MAP_DEFAULT.at(key)(*this);
        else
            return displayErrorKey(key);
    }
    return true;
}
