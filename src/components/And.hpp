/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** And
*/

#ifndef AND_HPP_
#define AND_HPP_

#include "AComponent.hpp"

namespace component
{
    class And : public nts::AComponent {
        public:
            And() : nts::AComponent("And", {0, 1}, {2}) { std::cout << "/* message */" << std::endl;}

            nts::Tristate compute(std::size_t pin = 1) override { return nts::UNDEFINED; }
            void simulate(std::size_t tick) override {}

        protected:
        private:
    };
} // namespace component



#endif /* !AND_HPP_ */
