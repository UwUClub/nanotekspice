/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4069
*/

#ifndef UWUNANO_4069_HPP_
#define UWUNANO_4069_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Gate4069 : public nts::AComponent {
        public:
            Gate4069(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);
            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};
            static nts::Tristate compute(nts::Tristate a);
    };
} // namespace nts


#endif /* !4069_HPP_ */
