/*
** EPITECH PROJECT, 2023
** nts/Component/IComponent.hpp
** File description:
** Interface for Components
*/

#pragma once
#include <iostream>
#include <memory>
#include <nts/Tristate.hpp>
#include "nts/Component/Component.hpp"

namespace nts
{
    struct Link_s;

    class IComponent;

    using Component = std::shared_ptr<nts::IComponent>;

    class IComponent
    {
    public:
        virtual ~IComponent(void) = default;
        //
        virtual nts::Tristate operator[](std::size_t pin) = 0;
        virtual void operatorAll(void) = 0;
        // Main NTS logic
        virtual void simulate(std::size_t tick) = 0;
        virtual void preCompute(void) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void postCompute(void) = 0;
        virtual void setLink(std::size_t pin, nts::Component other, \
            std::size_t otherPin) = 0;
        virtual nts::Tristate getLink(std::size_t pin) const = 0;
        //
        virtual bool isValidPin(size_t const pin) const = 0;
        virtual bool simulatedPin(size_t const pin, bool simulated) = 0;
        //
        virtual void setState(nts::Tristate const state) = 0;
        virtual nts::Tristate getState(void) const = 0;
        // isInput and isOutput
        virtual bool isInput(void) = 0;
        virtual bool isOutput(void) = 0;
        virtual bool isClock(void) = 0;
        virtual bool isIgnored(void) = 0;
        virtual void setIsInput(bool isInput) = 0;
        virtual void setIsInput(void) = 0;
        virtual void setIsOutput(bool isOutput) = 0;
        virtual void setIsOutput(void) = 0;
        virtual void setIsClock(bool isClock) = 0;
        virtual void setIsClock(void) = 0;
        virtual void setIsIgnored(bool isIgnored) = 0;
        virtual void setIsIgnored(void) = 0;
        //
        virtual bool push(struct nts::Link_s link) = 0;
        // For complexes
        virtual bool setToComplex(std::string const &filename) = 0;
        virtual void forceLink(nts::Component component, std::size_t pin) = 0;
    };

    struct Link_s {
        std::size_t pin;
        nts::Component other;
        std::size_t otherPin;
    };
}
