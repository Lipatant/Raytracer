/*
** EPITECH PROJECT, 2023
** Main.cpp
** File description:
** Main and starting function
*/

#include "nts/ComponentMap.hpp"
#include "nts/Exception.hpp"
#include "nts/Instruction.hpp"

bool setup(int const ac, char const * const * const av, \
    nts::InstructionList &list);
bool generate(nts::InstructionList &instructionList, \
    nts::ComponentMap &componentMap);
bool loop(nts::ComponentMap &componentMap);

int main(int const ac, char const * const * const av)
{
    nts::InstructionList instructionList;
    nts::ComponentMap componentMap;

    if (!setup(ac, av, instructionList))
        return 84;
    if (!generate(instructionList, componentMap))
        return 84;
    if (!loop(componentMap))
        return 84;
    return 0;
}
