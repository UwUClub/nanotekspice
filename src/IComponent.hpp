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
#include <vector>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void setInput(std::size_t pin, IComponent *other, std::size_t otherPin) = 0;
            virtual std::map<std::size_t, std::pair<nts::IComponent *, std::size_t>> getInputs() const = 0;
            virtual std::map<std::size_t, std::vector<nts::IComponent *>> getOutputs() const = 0;
            virtual const std::string &getType() const = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
