//
// Created by Beafowl on 2/6/23.
//

#ifndef NANOTEKSPICE_INPUT_HPP
#define NANOTEKSPICE_INPUT_HPP

#include "AComponent.hpp"

namespace component
{
    class Input : public nts::AComponent {
        public:
            Input() : nts::AComponent("Input", {}, {0}) { std::cout << "/* create input */" << std::endl;}

            nts::Tristate compute(std::size_t pin = 1) override { return nts::UNDEFINED; }
            void simulate(std::size_t tick) override {}

        protected:
        private:
    };
} // namespace component

#endif //NANOTEKSPICE_INPUT_HPP
