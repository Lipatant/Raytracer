/*
** EPITECH PROJECT, 2023
** nts/Component/Input.cpp
** File description:
** Functions for nts/Component/Input.hpp
*/

#include "nts/Component/Input.hpp"

nts::OutputComponent::OutputComponent(void)
{
    setIsOutput(true);
    clearPinData();
    addPinData(true);   //1 -in
    if (isValidPin(1))
        _pinDatas[0].hasBeenSimulated = false;
}

void nts::InputComponent::forceLink(nts::Component component, std::size_t pin)
{
    isComponentRedirection = true;
    componentRedirection = component;
    componentRedirectionPin = pin;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (!isComponentRedirection) {
        if (isValidPin(1))
            return _pinDatas[(pin - 1) % _pinDatas.size()].state;
        else
            return nts::Tristate::Undefined;
    }
    return componentRedirection->getLink(componentRedirectionPin);
}

void nts::OutputComponent::forceLink(nts::Component component, std::size_t pin)
{
    if (!isValidPin(1))
        return;
}
