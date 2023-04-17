/*
** EPITECH PROJECT, 2023
** nts/Instruction/Parsing.hpp
** File description:
** -
*/

#pragma once
#include <map>
#include "nts/Instruction/Structs.hpp"
#include "nts/Instruction/Types.hpp"

namespace nts
{
namespace instruction
{
namespace parsing
{
    static const std::map<nts::instruction::Type, std::string> REGEXES {
        {nts::instruction::Type::Comment, "^\\s*$"},
        {nts::instruction::Type::Statement, "^\\.\\w+:(\\s)*$"},
        {nts::instruction::Type::Chipset, "^\\w+(\\s)+\\w+(\\s)*$"},
        {nts::instruction::Type::Link, "^\\w+:\\d+(\\s)+\\w+:\\d+(\\s)*$"},
    };

    void parseLineStatement(std::string const &line, \
        struct Instruction_s &instruction);

    void parseLineChipset(std::string const &line, \
        struct Instruction_s &instruction);

    void parseLineLink(std::string const &line, \
        struct Instruction_s &instruction);

    static const std::map<nts::instruction::Type, void (*) \
        (std::string const &, struct Instruction_s &)> PARSING_FUNCTIONS {
        {nts::instruction::Type::Statement, parseLineStatement},
        {nts::instruction::Type::Chipset, parseLineChipset},
        {nts::instruction::Type::Link, parseLineLink},
    };

    /// @brief Take a string as argument and returns an Instruction_s
    /// @param line Line to parse (std::string const &)
    /// @param type Type of the line
    /// @return struct nts::Instruction_s
    /// @exception nts::exception::parsing::UnknownLineFormating(line)
    struct nts::Instruction_s parseLine(std::string const &line, \
        nts::instruction::Type const type);
    /// @brief Take a string as argument and returns an Instruction_s
    /// @param line Line to parse (std::string const &)
    /// @return struct nts::Instruction_s
    /// @exception nts::exception::parsing::UnknownLineFormating(line)
    struct nts::Instruction_s parseLine(std::string const &line);
}
}
}
