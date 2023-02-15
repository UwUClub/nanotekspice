/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4001
*/

#ifndef UWUNANO_4001_HPP_
#define UWUNANO_4001_HPP_

#include "AComposedComponent.hpp"

namespace nts::component
{
    class Gate4001 final: public nts::AComposedComponent {
        public:
            /*Gate4001(const std::string &name,
                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins =
                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>{
                    std::make_pair(std::vector<std::size_t>{1, 2}, std::vector<std::size_t>{3}),
                    std::make_pair(std::vector<std::size_t>{5, 6}, std::vector<std::size_t>{4}),
                    std::make_pair(std::vector<std::size_t>{8, 9}, std::vector<std::size_t>{10}),
                    std::make_pair(std::vector<std::size_t>{12, 13}, std::vector<std::size_t>{11})
            });*/
            Gate4001();

            nts::Tristate compute(std::size_t pin = 1) final;
    };
} // namespace nts

#endif /* !UWUNANO_4001_HPP_ */
