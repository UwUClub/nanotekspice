/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4011
*/

#ifndef UWUNANO_4011_HPP_
#define UWUNANO_4011_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Gate4011 : public nts::AComponent {
        public:
            Gate4011(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);
            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};
    };
} // namespace nts

#endif /* !UWUNANO_4001_HPP_ */
