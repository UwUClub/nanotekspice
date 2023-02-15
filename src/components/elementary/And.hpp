/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** And
*/

#ifndef AND_HPP_
#define AND_HPP_

#include "AComponent.hpp"

namespace nts::component
    {
        class And : public nts::AComponent {
            public:
            And(const std::string &name,
                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins =
                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>{std::make_pair(std::vector<std::size_t>{1, 2}, std::vector<std::size_t>{3})});

            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};

            static nts::Tristate compute(nts::Tristate a, nts::Tristate b);

            protected:
            private:
        };
    }

#endif /* !AND_HPP_ */
