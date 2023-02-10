/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4008
*/

#ifndef UWUNANO_4008_HPP_
#define UWUNANO_4008_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Gate4008 : public nts::AComponent {
        public:
            Gate4008(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);
            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};
    };
} // namespace nts

#endif /* !UWUNANO_4008_HPP_ */