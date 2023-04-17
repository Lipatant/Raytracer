/*
** EPITECH PROJECT, 2023
** nts/Component/Logic/Xor.hpp
** File description:
** Acts as a base for logic gates
*/

#pragma once
#include "nts/Component/Logic/Base.hpp"

namespace nts
{
    class XorComponent : public LogicComponent
    {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };
}
