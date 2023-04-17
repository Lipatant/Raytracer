/*
** EPITECH PROJECT, 2023
** nts/Instruction/Parsing.cpp
** File description:
** -
*/

#include <regex>
#include "nts/Exception.hpp"
#include "nts/Instruction/Parsing.hpp"
#include "Utility/Regex.hpp"

static bool _testRegexFromType(std::string const &line, \
    nts::instruction::Type const type)
{
    if (nts::instruction::parsing::REGEXES.find(type) == \
        nts::instruction::parsing::REGEXES.end())
        return false;
    return utility::regex::quickTest(line, \
        nts::instruction::parsing::REGEXES.at(type));
}

static nts::instruction::Type _getLineType(std::string const &line)
{
    for (size_t i = 0; i < (size_t)nts::instruction::Type::SIZE; i++)
        if (_testRegexFromType(line, (nts::instruction::Type)i))
            return (nts::instruction::Type)i;
    throw nts::exception::parsing::UnknownLineFormating(line);
    return nts::instruction::Type::SIZE;
}

namespace nts
{
namespace instruction
{
namespace parsing
{
    void parseLineStatement(std::string const &line, \
        struct Instruction_s &instruction)
    {
        instruction.statement.content = utility::regex::firstMatch(line, \
            "\\w+(?=:(\\s)*$)");
    }

    void parseLineChipset(std::string const &line, \
        struct Instruction_s &instruction)
    {
        instruction.chipset.name = utility::regex::firstMatch(line, \
            "\\w+(?=(\\s)*$)");
        instruction.chipset.type = utility::regex::firstMatch(line, \
            "\\w+(?=(\\s)+\\w+(\\s)*$)");
    }

    void parseLineLink(std::string const &line, \
        struct Instruction_s &instruction)
    {
        instruction.link.source = utility::regex::firstMatch(line, \
            "^\\w+(?=:\\d+(\\s)+\\w+:\\d+(\\s)*$)");
        instruction.link.source_pin = std::stoul(utility::regex::firstMatch( \
            line, "\\d+(?=(\\s)+\\w+:\\d+(\\s)*$)"));
        instruction.link.target = utility::regex::firstMatch(line, \
            "\\w+(?=:\\d+(\\s)*$)");
        instruction.link.target_pin = std::stoul(utility::regex::firstMatch( \
            line, "\\d+(?=(\\s)*$)"));
    }

    struct nts::Instruction_s parseLine(std::string const &line, \
        nts::instruction::Type const type)
    {
        std::string parsedLine = line.substr(0, line.find("#"));
        nts::Instruction_s instruction;

        instruction.type = type;
        if (type == nts::instruction::Type::SIZE)
            return instruction;
        if (nts::instruction::parsing::PARSING_FUNCTIONS.find(type) != \
            nts::instruction::parsing::PARSING_FUNCTIONS.end())
            nts::instruction::parsing::PARSING_FUNCTIONS.at(type)(parsedLine, \
                instruction);
        return instruction;
    }
    struct nts::Instruction_s parseLine(std::string const &line)
    {
        return parseLine(line, _getLineType(line.substr(0, line.find("#"))));
    }
}
}
}
