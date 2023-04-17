/*
** EPITECH PROJECT, 2023
** nts/Component/Complex/Base.hpp
** File description:
** -
*/

#pragma once
#include <vector>
#include "nts/ComponentMap.hpp"
#include "nts/Component/AComponent.hpp"

namespace nts
{
    using ComplexComponentInner = std::vector<std::string>;

    class ComplexComponent : public AComponent
    {
    private:
        nts::ComponentMap _componentMap;
        nts::ComplexComponentInner _componentInner;
    public:
        ComplexComponent(void) { clearPinData(); }
        //
        void operatorAll(void) override;
        void preCompute(void) override;
        nts::Tristate compute(std::size_t pin) override;
        void postCompute(void) override;
        //
        void setLink(std::size_t pin, Component other, \
            std::size_t otherPin) override;
        //
        bool setToComplex(std::string const &filename) override;
    };
}
