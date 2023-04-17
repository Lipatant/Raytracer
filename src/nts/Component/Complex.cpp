/*
** EPITECH PROJECT, 2023
** nts/Component/Complex.cpp
** File description:
** Functions for nts/Component/Complex.hpp
*/

#include <fstream>
#include "nts/Component/Complex.hpp"
#include "nts/Exception.hpp"
#include "nts/Instruction.hpp"

bool setup(int const ac, char const * const * const av, \
    nts::InstructionList &list);
bool generate(nts::InstructionList &instructionList, \
    nts::ComponentMap &componentMap);

void nts::ComplexComponent::preCompute(void)
{
    std::size_t size = _pinDatas.size();

    for (const auto &component : _componentMap.map())
        component.second->preCompute();
    for (std::size_t i = 0; i < size; i++)
        _pinDatas[i].hasBeenSimulated = false;
}

nts::Tristate nts::ComplexComponent::compute(std::size_t pin)
{
    std::string component = _componentInner[pin - 1];

    if (_componentMap[component]->isInput() && \
        !_componentMap[component]->isClock()) {
        _componentMap[component]->setState(getLink(pin));
        _componentMap[component]->preCompute();
        _componentMap[component]->simulatedPin(1, true);
        return _componentMap[component]->getState();
    }
//    return nts::Tristate::True;
    return _componentMap[component]->operator[](1);
}

void nts::ComplexComponent::postCompute(void)
{
    std::size_t tick = 0;
    for (const auto &component : _componentMap.map())
        component.second->postCompute();
}

void nts::ComplexComponent::operatorAll(void)
{
    for (const auto &component : _componentMap.map())
        component.second->operatorAll();
}

void nts::ComplexComponent::setLink(std::size_t pin, Component other, \
    std::size_t otherPin)
{
    this->push({pin, other, otherPin});
    if (!isValidPin(pin))
        return;
    _componentMap[_componentInner[pin - 1]]->forceLink(other, otherPin);
}

bool nts::ComplexComponent::setToComplex(std::string const &filename)
{
    nts::InstructionList instructionList;
    std::string filepath = "./components/" + filename + ".nts";
    std::size_t size;
    char const *av[2] = {"", filepath.c_str()};

    if (!setup(2, av, instructionList))
        return false;
    if (!generate(instructionList, _componentMap))
        return false;
    _componentInner.clear();
    clearPinData();
    for (const auto &component : _componentMap.map()) {
        if (!component.second->isInput() && !component.second->isOutput() && \
            !component.second->isIgnored())
            continue;
        _componentInner.push_back(component.first);
        addPinData(false, component.second->getState());
    }
    return true;
}
