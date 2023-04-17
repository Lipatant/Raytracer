/*
** EPITECH PROJECT, 2023
** Generate/add.cpp
** File description:
** -
*/

#include <typeinfo>
#include "nts/ComponentFactory.hpp"
#include "nts/ComponentMap.hpp"
#include "nts/Instruction.hpp"
#include "nts/Exception.hpp"

void generateAddComponent(struct nts::Instruction_s const list, \
    nts::ComponentMap &map)
{
    if (map.mode() != nts::instruction::Mode::Chipset)
        throw nts::exception::parsing::ChipsetOutside(list.chipset.name);
    if (map.isKey(list.chipset.name))
        throw nts::exception::parsing::ShareSameName(list.chipset.name);
    map.addValue(list.chipset.name, nts::ComponentFactory(list.chipset.type));
}

void generateAddLink(struct nts::Instruction_s const list, \
    nts::ComponentMap &map)
{
    if (map.mode() != nts::instruction::Mode::Link)
        throw nts::exception::parsing::ChipsetOutside(list.link.source);
    if (!map.isKey(list.link.source))
        throw nts::exception::parsing::UnknownComponentName(list.link.source);
    if (!map.getValue(list.link.source)->isValidPin(list.link.source_pin))
        throw nts::exception::InvalidPin(list.link.source + ":" + \
            std::to_string(list.link.source_pin));
    if (!map.getValue(list.link.target)->isValidPin(list.link.target_pin))
        throw nts::exception::InvalidPin(list.link.target + ":" + \
            std::to_string(list.link.target_pin));
    if (list.link.source == list.link.target && list.link.source_pin == \
        list.link.target_pin)
        throw nts::exception::parsing::LinkToItself(list.link.source);
    map.getValue(list.link.source)->setLink(list.link.source_pin, \
        map.getValue(list.link.target), list.link.target_pin);
    map.getValue(list.link.target)->setLink(list.link.target_pin, \
        map.getValue(list.link.source), list.link.source_pin);
}

void generateAddStatement(struct nts::Instruction_s const list, \
    nts::ComponentMap &map)
{
    if (nts::instruction::MODES.find(list.statement.content) == \
        nts::instruction::MODES.end())
        throw nts::exception::parsing::UnknownStatement( \
            list.statement.content);
    map.mode() = nts::instruction::MODES.at(list.statement.content);
}

void generateAdd(struct nts::Instruction_s const list, nts::ComponentMap &map)
{
    if (list.type == nts::instruction::Type::Statement)
        generateAddStatement(list, map);
    if (list.type == nts::instruction::Type::Chipset)
        generateAddComponent(list, map);
    if (list.type == nts::instruction::Type::Link)
        generateAddLink(list, map);
    return;
}
