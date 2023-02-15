/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4030
*/

#ifndef UWUNANO_4030_HPP_
#define UWUNANO_4030_HPP_

#include "AComposedComponent.hpp"

namespace nts::component
{
    class Gate4030 final : public nts::AComposedComponent {
        public:
            Gate4030();

            nts::Tristate compute(std::size_t pin = 1) final;
    };
} // namespace nts


#endif /* !4030_HPP_ */
