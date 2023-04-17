/*
** EPITECH PROJECT, 2023
** Loop/Display.cpp
** File description:
** -
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include "nts/ComponentMap.hpp"

struct element_s {
    std::string name;
    nts::Tristate state;
};

bool compareElements(const struct element_s &a, const struct element_s &b)
{
    return a.name < b.name;
}

bool loopDisplay(nts::ComponentMap &componentMap, std::string const &in, \
    size_t &tick)
{
    std::vector<struct element_s> inputs;
    std::vector<struct element_s> inputs_it;
    std::vector<struct element_s> outputs;

    for (nts::ComponentMapMap::iterator i = componentMap.map().begin(); \
        i != componentMap.map().end(); i++) {
        if (i->second->isInput())
            inputs.push_back({i->first, i->second->operator[](1)});
        if (i->second->isOutput())
            outputs.push_back({i->first, i->second->operator[](1)});
    }
    std::sort(inputs.begin(), inputs.end(), compareElements);
    std::sort(outputs.begin(), outputs.end(), compareElements);
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto const &i : inputs) {
        if (i.state == nts::Tristate::Undefined)
            std::cout << "  " << i.name << ": U" << std::endl;
        else
            std::cout << "  " << i.name << ": " << i.state << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto const &i : outputs) {
        if (i.state == nts::Tristate::Undefined)
            std::cout << "  " << i.name << ": U" << std::endl;
        else
            std::cout << "  " << i.name << ": " << i.state << std::endl;
    }
    return true;
}

//std::cout << "  " << "???" << ": " << "?" << std::endl;
