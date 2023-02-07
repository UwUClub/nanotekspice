/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "AComponent.hpp"

namespace nts::component
    {
        class Input : public nts::AComponent {
            public:
                Input(const std::string &name, const std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>& pins);
                ~Input() override;

                nts::Tristate compute(std::size_t pin) override { return _outputs[pin]; }
                void simulate(std::size_t tick) override {}
            protected:
            private:
};
    } // namespace nts

#endif /* !INPUT_HPP_ */
