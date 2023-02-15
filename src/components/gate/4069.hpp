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
            Gate4069(const std::string &name,
            std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins =
            std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>{
                std::make_pair(std::vector<std::size_t>{1}, std::vector<std::size_t>{2}),
                std::make_pair(std::vector<std::size_t>{3}, std::vector<std::size_t>{4}),
                std::make_pair(std::vector<std::size_t>{5}, std::vector<std::size_t>{6}),
                std::make_pair(std::vector<std::size_t>{9}, std::vector<std::size_t>{8}),
                std::make_pair(std::vector<std::size_t>{11}, std::vector<std::size_t>{10}),
                std::make_pair(std::vector<std::size_t>{13}, std::vector<std::size_t>{12})
                });

            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};
            static nts::Tristate compute(nts::Tristate a);
    };
} // namespace nts


#endif /* !4069_HPP_ */
