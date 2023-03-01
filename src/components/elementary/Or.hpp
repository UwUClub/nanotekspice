/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Or
*/

#ifndef OR_HPP_
#define OR_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Or final : public nts::AComponent {
        public:
            Or();

            nts::Tristate compute(std::size_t pin = 1) final;

        private:
            nts::Tristate getTruthTableOutput(nts::Tristate a, nts::Tristate b);
            nts::Tristate getSeqState(nts::Tristate a);
            size_t _counter;
    };
} // namespace nts

#endif /* !OR_HPP_ */
