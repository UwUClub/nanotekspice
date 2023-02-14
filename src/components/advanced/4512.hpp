/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4512
*/

#ifndef UWUNANO_4512_HPP_
#define UWUNANO_4512_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Gate4512 : public nts::AComponent {
        public:
            Gate4512(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);
            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};
    };
}

#endif /* !4512_HPP_ */
