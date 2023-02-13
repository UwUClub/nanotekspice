/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
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
            virtual int getNbPinsIn() const = 0;
            virtual int getNbPinsOut() const = 0;
            virtual bool isInput(std::size_t pin) const = 0;
            virtual bool isOutput(std::size_t pin) const = 0;
            virtual const std::string &getName() const = 0;
            virtual nts::CompType getType() const = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
