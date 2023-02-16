/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Or
*/

#ifndef XOR_HPP_
#define XOR_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Xor final : public nts::AComponent {
        public:
            Xor();

            nts::Tristate compute(std::size_t pin = 1) final;

        private:
            nts::Tristate getTruthTableOutput(nts::Tristate a, nts::Tristate b);
    };
} // namespace nts

#endif /* !XOR_HPP_ */
