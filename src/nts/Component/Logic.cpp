/*
** EPITECH PROJECT, 2023
** nts/Component/Logic.cpp
** File description:
** Functions for nts/Component/Logic.hpp
*/

#include <list>
#include "nts/Component/Logic.hpp"

nts::LogicComponent::LogicComponent(void)
{
    clearPinData();
    addPinData(true);   //1 -in1
    addPinData(true);   //2 -in2
    addPinData();       //3 -out
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    nts::Tristate pins[2] = {operator[](1), operator[](2)};

    if (pins[0] == nts::Tristate::False || pins[1] == nts::Tristate::False)
        return nts::Tristate::False;
    if (pins[0] == nts::Tristate::Undefined || pins[1] == \
        nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    return static_cast<nts::Tristate>(static_cast<bool>(pins[0]) & \
        static_cast<bool>(pins[1]));
}

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    nts::Tristate pins[2] = {operator[](1), operator[](2)};

    if (pins[0] == nts::Tristate::True || pins[1] == nts::Tristate::True)
        return nts::Tristate::True;
    if (pins[0] == nts::Tristate::Undefined || pins[1] == \
        nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    return static_cast<nts::Tristate>(static_cast<bool>(pins[0]) | \
        static_cast<bool>(pins[1]));
}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    nts::Tristate pins[2] = {operator[](1), operator[](2)};

    if (pins[0] == nts::Tristate::Undefined || pins[1] == \
        nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    return static_cast<nts::Tristate>(static_cast<bool>(pins[0]) ^ \
        static_cast<bool>(pins[1]));
}

nts::NotComponent::NotComponent(void)
{
    clearPinData();
    addPinData(true);   //1 -in
    addPinData();       //2 -out
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    nts::Tristate state = operator[](1);

    if (state == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    return state == nts::Tristate::True ? nts::Tristate::False : \
        nts::Tristate::True;
}
