/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4081
*/

#ifndef UWUNANO_4081_HPP_
#define UWUNANO_4081_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Gate4081 : public nts::AComponent {
        public:
            Gate4081(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);
            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};
    };
} // namespace nts

#endif /* !4081_HPP_ */
