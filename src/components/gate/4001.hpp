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
            Gate4001();

            nts::Tristate compute(std::size_t pin = 1) final;
    };
} // namespace nts

#endif /* !UWUNANO_4001_HPP_ */
