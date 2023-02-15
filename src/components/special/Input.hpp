/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "AShell.hpp"

namespace nts::component
    {
        class Input : public nts::AShell {
            public:
                Input(const std::string &name,
                    const std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>& pins =
                    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>{std::make_pair(std::vector<std::size_t>{}, std::vector<std::size_t>{1})});

                nts::Tristate compute(std::size_t pin) override;
                void simulate(std::size_t tick) override;
            protected:
            private:
};
    } // namespace nts

#endif /* !INPUT_HPP_ */
