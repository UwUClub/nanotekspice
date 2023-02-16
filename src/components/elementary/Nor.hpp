/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Nor
*/

#ifndef NOR_HPP_
#define NOR_HPP_

#include "AComposedComponent.hpp"

namespace nts::component
{
    class Nor final : public nts::AComposedComponent {
        public:
            Nor();

            nts::Tristate compute(std::size_t pin = 1) final;
    };
} // namespace nts

#endif /* !NOR_HPP_ */
