/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4071
*/

#ifndef UWUNANO_4071_HPP_
#define UWUNANO_4071_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Gate4071 : public nts::AComponent {
        public:
            Gate4071(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);
            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};

            static nts::Tristate compute(nts::Tristate a, nts::Tristate b);
    };
} // namespace nts

#endif /* !4071_HPP_ */
