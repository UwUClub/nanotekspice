/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4011
*/

#ifndef UWUNANO_4011_HPP_
#define UWUNANO_4011_HPP_

#include "AComposedComponent.hpp"

namespace nts::component
{
    class Gate4011 final: public nts::AComposedComponent {
        public:
            Gate4011();

            nts::Tristate compute(std::size_t pin = 1) final;
    };
} // namespace nts

#endif /* !UWUNANO_4001_HPP_ */
