/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4081
*/

#ifndef UWUNANO_4081_HPP_
#define UWUNANO_4081_HPP_

#include "AComposedComponent.hpp"

namespace nts::component
{
    class Gate4081 final : public nts::AComposedComponent {
        public:
            Gate4081();

            nts::Tristate compute(std::size_t pin = 1) override;
    };
} // namespace nts

#endif /* !4081_HPP_ */
