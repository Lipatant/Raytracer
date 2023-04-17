/*
** EPITECH PROJECT, 2023
** nts/ComponentFactory.cpp
** File description:
** -
*/

#include <string.h>
#include "nts/ComponentFactory.hpp"
#include "nts/Exception.hpp"

nts::Component nts::ComponentFactory(std::string const key)
{
    nts::Component complex;

    if (nts::COMPONENT_FACTORY.find(key) != nts::COMPONENT_FACTORY.end())
        return nts::COMPONENT_FACTORY.at(key)();
    complex = nts::componentFactoryOutput<nts::ComplexComponent>();
    if (!complex->setToComplex(key))
        throw nts::exception::parsing::UnknownComponentType(key);
    return complex;
}
