/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4069
*/

#ifndef UWUNANO_4069_HPP_
#define UWUNANO_4069_HPP_

#include "AComposedComponent.hpp"

namespace nts::component
{
    class Gate4069 final : public nts::AComposedComponent {
        public:
            Gate4069();

            nts::Tristate compute(std::size_t pin = 1) final;
    };
} // namespace nts


#endif /* !4069_HPP_ */
