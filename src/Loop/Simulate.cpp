/*
** EPITECH PROJECT, 2023
** Loop/Simulate.cpp
** File description:
** -
*/

#include "nts/ComponentMap.hpp"

bool loopSimulate(nts::ComponentMap &componentMap, std::string const &in, \
    size_t &tick)
{
    tick++;
    for (nts::ComponentMapMap::iterator i = componentMap.map().begin(); \
        i != componentMap.map().end(); i++)
        i->second->preCompute();
    for (nts::ComponentMapMap::iterator i = componentMap.map().begin(); \
        i != componentMap.map().end(); i++)
        i->second->operatorAll();
    for (nts::ComponentMapMap::iterator i = componentMap.map().begin(); \
        i != componentMap.map().end(); i++)
        i->second->postCompute();
    return true;
}
