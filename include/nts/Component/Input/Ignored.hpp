/*
** EPITECH PROJECT, 2023
** nts/Component/Input/Ignored.hpp
** File description:
** -
*/

#pragma once
#include "nts/Component/Input/Base.hpp"

namespace nts
{
    class IgnoredComponent : public StateComponent<>
    {
    public:
        IgnoredComponent(void) : StateComponent() { setIsIgnored(true); }
    };
}
