/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** And
*/

#ifndef AND_HPP_
#define AND_HPP_

#include <map>
#include "AComponent.hpp"

namespace nts::component
    {
        class And final : public nts::AComponent {
            public:
                And();

                nts::Tristate compute(std::size_t pin = 1) final;

            private:
                nts::Tristate getTruthTableOutput(nts::Tristate a, nts::Tristate b);
        };
    }

#endif /* !AND_HPP_ */
