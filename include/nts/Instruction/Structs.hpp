/*
** EPITECH PROJECT, 2023
** nts/Instruction/Struct.hpp
** File description:
** -
*/

#pragma once
#include <iostream>
#include <list>
#include "nts/Instruction/Types.hpp"

namespace nts
{
    struct Instruction_s {
        nts::instruction::Type type = nts::instruction::Type::Comment;
//        union
//        {
            nts::instruction::Comment comment;
            nts::instruction::Statement statement;
            nts::instruction::Chipset chipset;
            nts::instruction::Link link;
//        };
    };

    using InstructionList = std::list<struct Instruction_s>;
}
