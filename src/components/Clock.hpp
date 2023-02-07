/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "AComponent.hpp"

namespace nts
{
    namespace component
    {
        class Clock : public nts::AComponent {
            public:
                Clock(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);
                ~Clock();

                nts::Tristate compute(std::size_t pin) override;
                void simulate(std::size_t tick) override;

            protected:
            private:
        };
    } // namespace component
} // namespace nts

#endif /* !CLOCK_HPP_ */
