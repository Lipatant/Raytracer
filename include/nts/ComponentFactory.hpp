/*
** EPITECH PROJECT, 2023
** nts/ComponentFactory.hpp
** File description:
** Factory generating other Components from a string
*/

#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <typeindex>
#include "nts/Component.hpp"

namespace nts
{
    template <typename T>
    nts::Component componentFactoryOutput(void) \
        { return std::make_shared<T>(); }

    static const std::map<std::string, nts::Component (*) \
        (void)> COMPONENT_FACTORY {
        {"input", componentFactoryOutput<nts::InputComponent>},
        {"output", componentFactoryOutput<nts::OutputComponent>},
        {"true", componentFactoryOutput<nts::TrueComponent>},
        {"false", componentFactoryOutput<nts::FalseComponent>},
        {"clock", componentFactoryOutput<nts::ClockComponent>},
        {"and", componentFactoryOutput<nts::AndComponent>},
        {"not", componentFactoryOutput<nts::NotComponent>},
        {"or", componentFactoryOutput<nts::OrComponent>},
        {"xor", componentFactoryOutput<nts::XorComponent>},
        {"ignored", componentFactoryOutput<nts::IgnoredComponent>},
    };

    nts::Component ComponentFactory(std::string const key);
}
