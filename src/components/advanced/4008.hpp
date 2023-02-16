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
    class Gate4008 final : public nts::AComposedComponent {
        public:
            Gate4008();

            nts::Tristate compute(std::size_t pin = 1) final;
    };
} // namespace nts

#endif /* !UWUNANO_4008_HPP_ */