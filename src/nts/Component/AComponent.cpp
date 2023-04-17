/*
** EPITECH PROJECT, 2023
** nts/AComponent.cpp
** File description:
** Class using IComponent
*/

#include "nts/Component/AComponent.hpp"
#include "nts/Exception.hpp"

nts::Tristate nts::AComponent::operator[](std::size_t pin)
{
    nts::Tristate stateReturned;
    nts::Tristate state;
    std::size_t size = _pinDatas.size();

    if (!isValidPin(pin))
        throw nts::exception::InvalidPin();
    stateReturned =  _pinDatas[pin - 1].state;
    if (_pinDatas[pin - 1].hasBeenSimulated)
        return stateReturned;
    for (std::size_t i = 1; i <= size; i++) {
        if (_pinDatas[i - 1].hasBeenSimulated)
            continue;
        _pinDatas[i - 1].hasBeenSimulated = true;
        if (_pinDatas[i - 1].isRedirect)
            state = getLink(i);
        else
            state = compute(i);
        _pinDatas[i - 1].state = state;
        if (pin == i)
            stateReturned = state;
    }
    return stateReturned;
}

void nts::AComponent::operatorAll(void)
{
    std::size_t size = _pinDatas.size();

    for (std::size_t i = 1; i <= size; i++)
        operator[](i);
}

void nts::AComponent::preCompute(void)
{
    std::size_t size = _pinDatas.size();

    for (std::size_t i = 0; i < size; i++)
        _pinDatas[i].hasBeenSimulated = false;
}

void nts::AComponent::postCompute(void)
{
    return;
}

void nts::AComponent::setLink(std::size_t pin, Component other, \
    std::size_t otherPin)
{
    this->push({pin, other, otherPin});
}

nts::Tristate nts::AComponent::getLink(std::size_t pin) const
{
    nts::Tristate state = nts::Tristate::Undefined;
    nts::Tristate returned = nts::Tristate::Undefined;
    size_t iterations = 0;

    for (auto const &i : _list) {
        if (i.pin != pin)
            continue;
        iterations += 1;
        state = i.other->operator[](i.otherPin);
        if (iterations != 1 && state != returned)
            returned = nts::Tristate::Undefined;
        else
            returned = state;
    }
    return state;
}

bool nts::AComponent::push(struct nts::Link_s link)
{
    this->_list.push_back(link);
    return true;
}

bool nts::AComponent::isValidPin(size_t const pin) const
{
    return (pin != 0 && pin <= _pinDatas.size());
}

bool nts::AComponent::simulatedPin(size_t const pin, bool simulated)
{
    if (!isValidPin(pin))
        return false;
    _pinDatas[pin - 1].hasBeenSimulated = simulated;
    return true;
}

void nts::AComponent::addPinData(bool const isRedirect, \
    nts::Tristate const state)
{
    _pinDatas.push_back({isRedirect, true, state});
}

void nts::AComponent::addPinData(bool const isRedirect)
{
    addPinData(isRedirect, nts::Tristate::Undefined);
}

void nts::AComponent::addPinData(nts::Tristate const state)
{
    addPinData(false, state);
}

void nts::AComponent::addPinData(void)
{
    addPinData(false, nts::Tristate::Undefined);
}

void nts::AComponent::clearPinData(void)
{
    _pinDatas.clear();
}
