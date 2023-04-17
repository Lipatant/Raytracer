/*
** EPITECH PROJECT, 2023
** nts/Component/Input/Base.hpp
** File description:
** -
*/

#pragma once
#include "nts/Component/AComponent.hpp"

namespace nts
{
    template <nts::Tristate STATE = nts::Tristate::Undefined>
    class StateComponent : public AComponent
    {
    public:
        StateComponent(void);
        void preCompute(void) override;
        nts::Tristate compute(std::size_t pin) override;
        void postCompute(void) override;
    };

    using TrueComponent = StateComponent<nts::Tristate::True>;

    using FalseComponent = StateComponent<nts::Tristate::False>;
}

template <nts::Tristate STATE>
nts::StateComponent<STATE>::StateComponent(void)
{
    setState(STATE);
    clearPinData();
    addPinData(STATE);  //1 -out
//    if (STATE == nts::Tristate::Undefined || !isValidPin(1))
//        return;
//    _pinDatas[0].state = getState();
}

template <nts::Tristate STATE>
void nts::StateComponent<STATE>::preCompute(void)
{
    if (!isValidPin(1))
        return;
    _pinDatas[0].hasBeenSimulated = false;
    _pinDatas[0].state = getState();
}

template <nts::Tristate STATE>
nts::Tristate nts::StateComponent<STATE>::compute(std::size_t pin)
{
    nts::Tristate state = _pinDatas[(pin - 1) % _pinDatas.size()].state;

    return state;
}

template <nts::Tristate STATE>
void nts::StateComponent<STATE>::postCompute(void)
{
    nts::Tristate state;

    if (!isValidPin(1))
        return;
    state = _pinDatas[0].state;
    if (state != nts::Tristate::Undefined && isClock())
        state = state == nts::Tristate::True ? nts::Tristate::False : \
            nts::Tristate::True;
    setState(state);
}
