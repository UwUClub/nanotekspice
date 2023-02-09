/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Circuit
*/

#ifndef Circuit_HPP_
#define Circuit_HPP_

#include <map>
#include <vector>
#include <string>
#include "IComponent.hpp"

namespace nts
{
    class Circuit final {
        public:
            static Circuit *getInstance();
            ~Circuit();
            void setLink(nts::IComponent &component, std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void addComponent(nts::IComponent &component);
            nts::Tristate compute(nts::IComponent &component, std::size_t pin);
            void simulate(std::size_t tick);
            IComponent *getCompByName(std::string &name);
            void setOutput(const std::string& name, nts::Tristate state);
            size_t getNbOccurencesType(CompType type);

        private:
            Circuit() = default;
            Circuit(const Circuit &) = delete;

            enum class Type {
                INPUT,
                OUTPUT
            };

            std::map<nts::IComponent *, std::map<Type, std::vector<std::pair<size_t, nts::IComponent *>>>> _components;
    };
} // namespace nts
#endif /* !Circuit_HPP_ */
