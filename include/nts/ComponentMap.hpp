/*
** EPITECH PROJECT, 2023
** nts/ComponentMap.hpp
** File description:
** -
*/

#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include "Component/Component.hpp"
#include "Instruction/Modes.hpp"

namespace nts
{
    using ComponentMapValue = nts::Component;

    using ComponentMapPair = std::pair<std::string, nts::ComponentMapValue>;

    using ComponentMapMap = std::vector<nts::ComponentMapPair>;

    class ComponentMap
    {
    private:
        nts::ComponentMapMap _map;
        nts::instruction::Mode _mode = nts::instruction::Mode::None;
    public:
        nts::ComponentMapValue &operator[](std::string const &key);
        nts::ComponentMapPair &operator[](size_t const id);
        //
        bool isKey(std::string const key);
        bool addValue(std::string key, nts::ComponentMapValue value);
        nts::ComponentMapValue &getValue(std::string key);
        /// @brief Gets a direct access to the _mode member of the object
        nts::instruction::Mode &mode(void);
        /// @brief Gets a direct access to the _map member of the object
        ComponentMapMap &map(void);
    };
}
