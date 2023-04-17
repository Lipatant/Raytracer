/*
** EPITECH PROJECT, 2023
** nts/Component/AComponent.hpp
** File description:
** Class using IComponent
*/

#pragma once
#include <list>
#include <vector>
#include "nts/Component/IComponent.hpp"
#include "nts/Tristate.hpp"

namespace nts
{
    struct pinData_s {
        bool isRedirect;
        bool hasBeenSimulated;
        nts::Tristate state;
    };

    class AComponent : public IComponent
    {
    private:
        std::list<struct nts::Link_s> _list;
        std::list<struct nts::Link_s> _invertedList;
        bool _isInput = false;
        bool _isOutput = false;
        bool _isClock = false;
        bool _isIgnored = false;
        nts::Tristate _state = nts::Tristate::Undefined;
    protected:
        std::vector<struct pinData_s> _pinDatas;
    public:
        ~AComponent(void) = default;
        //
        nts::Tristate operator[](std::size_t pin) override;
        void operatorAll(void) override;
        // Main NTS logic
        void simulate(std::size_t tick) override { }
        void preCompute(void) override;
        void postCompute(void) override;
        void setLink(std::size_t pin, Component other, \
            std::size_t otherPin) override;
        nts::Tristate getLink(std::size_t pin) const final;
        //
        bool isValidPin(size_t const pin) const override;
        bool simulatedPin(size_t const pin, bool simulated) override;
        //
        void setState(nts::Tristate const state) final { _state = state; }
        nts::Tristate getState(void) const final { return _state; }
        // isInput and isOutput (inlines)
        bool isInput(void) final { return _isInput; }
        bool isOutput(void) final { return _isOutput; }
        bool isClock(void) final { return _isClock; }
        bool isIgnored(void) final { return _isIgnored; }
        void setIsInput(bool isInput) final { _isInput = isInput; }
        void setIsInput(void) final { _isInput = !_isInput; }
        void setIsOutput(bool isOutput) final { _isOutput = isOutput; }
        void setIsOutput(void) final { _isOutput = !_isOutput; }
        void setIsClock(bool isClock) final { _isClock = isClock; }
        void setIsClock(void) final { _isClock = !_isClock; }
        void setIsIgnored(bool isIgnored) final { _isIgnored = isIgnored; }
        void setIsIgnored(void) final { _isIgnored = !_isIgnored; }
        //
        bool push(struct nts::Link_s link) final;
        //
        void addPinData(bool const isRedirect, nts::Tristate const state);
        void addPinData(bool const isRedirect);
        void addPinData(nts::Tristate const state);
        void addPinData(void);
        void clearPinData(void);
        // Complexes
        bool setToComplex(std::string const &filename) override \
            { return false; }
        void forceLink(nts::Component component, std::size_t pin) override { }
    };
}
