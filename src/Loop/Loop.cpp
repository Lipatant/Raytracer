/*
** EPITECH PROJECT, 2023
** Loop/Loop.cpp
** File description:
** -
*/

#include <csignal>
#include <exception>
#include "nts/ComponentMap.hpp"

bool loopDisplay(nts::ComponentMap &componentMap, std::string const &in, \
    size_t &tick);
bool loopSimulate(nts::ComponentMap &componentMap, std::string const &in, \
    size_t &tick);

static volatile std::sig_atomic_t status = 0;

static void handler(int signal)
{
    status = signal;
}

bool loopLoop(nts::ComponentMap &componentMap, std::string const &in, \
    size_t &tick)
{
    std::signal(SIGINT, handler);

    while (true && status == 0) {
        loopSimulate(componentMap, in, tick);
        loopDisplay(componentMap, in, tick);
    }
    return true;
}
