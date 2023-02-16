/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4071
*/

#ifndef UWUNANO_4071_HPP_
#define UWUNANO_4071_HPP_

#include "AComposedComponent.hpp"

namespace nts::component
{
    class Gate4071 final : public nts::AComposedComponent {
        public:
            Gate4071();

            nts::Tristate compute(std::size_t pin = 1) final;
    };
} // namespace nts

#endif /* !4071_HPP_ */
