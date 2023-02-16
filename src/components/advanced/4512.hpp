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
    class Gate4512 final : public nts::AComponent {
        public:
            Gate4512(const std::string &name,
                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins =
                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>{
                    std::make_pair(std::vector<std::size_t>{1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 15}, std::vector<std::size_t>{14}),
                });
            Gate4512();
            nts::Tristate compute(std::size_t pin = 1) override;
    };
}

#endif /* !4512_HPP_ */
