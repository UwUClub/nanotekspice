/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "AShell.hpp"

namespace nts::component
{
    class Clock final : public nts::AShell {
        public:
            Clock();

            nts::Tristate compute(std::size_t pin) final;
            void simulate(std::size_t tick) final;
    };
} // namespace nts

#endif /* !CLOCK_HPP_ */
