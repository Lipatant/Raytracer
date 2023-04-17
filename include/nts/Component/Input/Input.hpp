/*
** EPITECH PROJECT, 2023
** nts/Component/Input/Input.hpp
** File description:
** -
*/

#pragma once
#include "nts/Component/Input/Base.hpp"

namespace nts
{
    class InputComponent : public StateComponent<>
    {
    private:
        nts::Component componentRedirection;
        std::size_t componentRedirectionPin;
        bool isComponentRedirection = false;
    public:
        InputComponent(void) : StateComponent() { setIsInput(true); }
        //
        nts::Tristate compute(std::size_t pin) override;
        //
        void forceLink(nts::Component component, std::size_t pin) override;
    };
}
