/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Or
*/

#ifndef NOT_HPP_
#define NOT_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Not final : public nts::AComponent {
        public:
            Not();

            nts::Tristate compute(std::size_t pin = 1) final;
    };
} // namespace nts

#endif /* !NOT_HPP_ */
