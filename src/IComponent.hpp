/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <map>

namespace nts
{

    enum class CompType {
        INPUT,
        OUTPUT,
        CLOCK,
        TRUE,
        FALSE,
        AND,
        OR,
        XOR,
        NOR,
        NAND,
        NOT,
        BUFFER,
        GATE_4001,
        GATE_4011,
        GATE_4030,
        GATE_4069,
        GATE_4071,
        GATE_4081,
        GATE_4008,
        GATE_4013,
        GATE_4512,
        CHIPSET,
        CIRCUIT,
        UNDEFINED,
        ROM
    };

    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void setInput(std::size_t pin, IComponent *other, std::size_t otherPin) = 0;
            virtual std::map<std::size_t, std::pair<nts::IComponent *, std::size_t>> getInputs() const = 0;
            virtual std::map<std::size_t, std::vector<nts::IComponent *>> getOutputs() const = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
