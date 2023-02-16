/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "AShell.hpp"

namespace nts::component {
        class Input final : public nts::AShell {
            public:
                Input();

                nts::Tristate compute(std::size_t pin) final;
                void simulate(std::size_t tick) final;
            protected:
            private:
    };
} // namespace nts

#endif /* !INPUT_HPP_ */
