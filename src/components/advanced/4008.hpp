/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4008
*/

#ifndef UWUNANO_4008_HPP_
#define UWUNANO_4008_HPP_

#include "AComposedComponent.hpp"

namespace nts::component
{
    class Gate4008 : public nts::AComposedComponent {
        public:
//            Gate4008(const std::string &name,
//                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins =
//                    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>{
//                        std::make_pair(std::vector<std::size_t>{15, 1}, std::vector<std::size_t>{13, 14}),
//                        std::make_pair(std::vector<std::size_t>{2, 3}, std::vector<std::size_t>{12}),
//                        std::make_pair(std::vector<std::size_t>{4, 5}, std::vector<std::size_t>{11}),
//                        std::make_pair(std::vector<std::size_t>{6, 7, 9}, std::vector<std::size_t>{10}),
//                    });
            Gate4008();

            nts::Tristate compute(std::size_t pin = 1) override;
    };
} // namespace nts

#endif /* !UWUNANO_4008_HPP_ */