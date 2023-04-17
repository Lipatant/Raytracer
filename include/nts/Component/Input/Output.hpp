/*
** EPITECH PROJECT, 2023
** nts/Component/Input/Output.hpp
** File description:
** -
*/

#pragma once
#include "nts/Component/Input/Base.hpp"

namespace nts
{
    class OutputComponent : public StateComponent<>
    {
    public:
        OutputComponent(void);
        //
        void forceLink(nts::Component component, std::size_t pin) override;
    };
}
