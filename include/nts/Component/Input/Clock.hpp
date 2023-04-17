/*
** EPITECH PROJECT, 2023
** nts/Component/Input/Clock.hpp
** File description:
** -
*/

#pragma once
#include "nts/Component/Input/Input.hpp"

namespace nts
{
    class ClockComponent : public InputComponent
    {
    public:
        ClockComponent(void) : InputComponent() { setIsClock(true); }
    };
}
