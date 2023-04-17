/*
** EPITECH PROJECT, 2023
** nts/Component/Logic/Not.hpp
** File description:
** Acts as a base for logic gates
*/

#pragma once
#include "nts/Component/AComponent.hpp"

namespace nts
{
    class NotComponent : public AComponent
    {
    public:
        NotComponent(void);
        nts::Tristate compute(std::size_t pin) override;
    };
}
