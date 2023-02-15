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
            Gate4011(const std::string &name,
                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins =
                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>{
                    std::make_pair(std::vector<std::size_t>{1, 2}, std::vector<std::size_t>{3}),
                    std::make_pair(std::vector<std::size_t>{5, 6}, std::vector<std::size_t>{4}),
                    std::make_pair(std::vector<std::size_t>{8, 9}, std::vector<std::size_t>{10}),
                    std::make_pair(std::vector<std::size_t>{12, 13}, std::vector<std::size_t>{11})
                });

            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};

            static nts::Tristate compute(nts::Tristate a, nts::Tristate b);
    };
} // namespace nts

#endif /* !UWUNANO_4001_HPP_ */
