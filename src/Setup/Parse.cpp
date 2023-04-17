/*
** EPITECH PROJECT, 2023
** Parse.cpp
** File description:
** Setup parsing
*/

#include <fstream>
#include <iostream>
#include "nts/Exception.hpp"
#include "nts/Instruction.hpp"

void setupParse(std::ifstream &stream, nts::InstructionList &list)
{
    std::string line;

    if (!stream.is_open())
        throw nts::exception::parsing::CantOpenFile();
    while (getline(stream, line))
        list.push_back(nts::instruction::parsing::parseLine(line));
}
